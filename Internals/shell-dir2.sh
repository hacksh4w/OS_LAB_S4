#!/bin/bash

read -p "Enter the directory path: " dirpath


if [ -d "$dirpath" ]; then    #checking if a directory exists, using `-d`
    echo "Directory exists."  
    read -p "Enter the file name: " filename
# `-p` vechu readingum printing a prompt message um  simultaneously nadathham
    file_path="$dirpath/$filename"

    
    touch "$file_path"   # touch for crrating a file
    echo "File $filename created."

    
    if [ -e "$file_path" ]; then
        echo "File exists."

        # Create a backup with the date of creation
        backup_filename="${filename}_$(date +%Y%m%d)"
        backup_path="$dirpath/$backup_filename"
        cp "$file_path" "$backup_path"

        if [ -f "$file_path" ]; then
            echo "File $filename backed up as $backup_filename."
            rm "$file_path"
            echo "File $filename deleted."
        else
            echo "Unknown file type."
        fi
    else
        echo "File does not exist."
    fi
else
    echo "Directory does not exist."
fi
