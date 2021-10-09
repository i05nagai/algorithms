#!/bin/sh

function version {
	echo "make_file_list version 0.0.1"
}    

function usage {
    cat <<EOF
make_file_list is a tool for generating source and file list.

Example:
	#generates all *.cmake files in cmake directory
	make_file_list
	#generates nm.cmake into cmake/nm.cmake
	make_file_list -p algo/nm

Usage:
    make_file_list [<options>]

Options:
	--version, -v     print basename version
	--help, -h        print this
	--debug, -d       debug mode
	--path, -p /path/to/target 	generates target.cmake from /path/to/target   
EOF
}

#output ${target_name}.cmake into ./cmake/
#header list includes *.hpp and *.h
#source list includes *.cpp
function make_file_list() {
	local num=$#
	local search_dir=$1
	local target_name=$2
	local output_dir="./cmake/"
	local output_path=${output_dir}${target_name}.cmake

	if [ $num -ne 2 ]; then
		exit 1
	fi

	find $search_dir -name "*.cpp" | sed -e 's/\s\+/\n/g' | sort > srcs.tmp
	find $search_dir -name "*.h" | sed -e 's/\s\+/\n/g' | sort > c_headers.tmp
	find $search_dir -name "*.hpp" | sed -e 's/\s\+/\n/g' | sort > cpp_headers.tmp

	echo "LIST (APPEND ${target_name}_SOURCES" > ${output_path}
	cat srcs.tmp | sed -e 's/^/    /g' >> ${output_path}
	echo ')' >> ${output_path}

	echo "LIST (APPEND ${target_name}_HEADERS" >> ${output_path}
	cat c_headers.tmp | sed -e 's/^/    /g' >> ${output_path}
	cat cpp_headers.tmp | sed -e 's/^/    /g' >> ${output_path}
	echo ')' >> ${output_path}

	rm -f srcs.tmp c_headers.tmp cpp_headers.tmp
	return 1
}

# generate all list in algo directory
function generate_all_file_list()
{
	local base_path="algo/"
	local input_dir=""
	local target_name=""

	for directory_name in `ls $base_path`; do
		target_name=`basename $directory_name`
		input_dir=$base_path$target_name
		make_file_list $input_dir $target_name
	done
}

while [ $# -gt 0 ];
do
	case ${1} in
		--debug|-d)
			set -x
		;;

		--help|-h)
			usage
			exit 0
		;;

		--version|-v)
			version
			exit 0
		;;

		--path|-p)
			target_path=${2}
			shift
		;;

		*)
			echo "[ERROR] Invalid option '${1}'"
			usage
			exit 1
		;;
	esac
	shift
done	

if [ -n "$target_path" ]; then
	target_name=`basename $target_path`
	make_file_list $target_path $target_name
else
	generate_all_file_list
fi


