#!/bin/bash

#check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
	echo "Usage: $0 <writefile> <writestr>"
	exit 1
fi

writefile=$1
writestr=$2

#create the directory path if it doesn't exist
mkdir -p "$(dirname "$writefile")"

#write content to the file
echo "$writestr" > "$writefile"

#check if the file was created succesfully
if [ $? -eq 0 ]; then
	echo "File $writefile created succesfully with content:"
	cat "$writefile"
else
	echo "Error: Could not create file $writefile"
	exit 1
fi

