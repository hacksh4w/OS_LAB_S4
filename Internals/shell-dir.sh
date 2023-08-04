#!/bin/bash

# `-p` vechu, readingum printing a prompt message um simultaneously nadathham
read -p "Enter 'create' to create a directory or 'delete' to delete a directory: " operation

if [ "$operation" = "create" ]; then
    read -p "Enter the directory path: " dirpath

    
    if [ -d "$dirpath" ]; then    #checking if a directory exists, using `-d`
        echo "Directory already exists."
    else
        
        mkdir "$dirpath"   # mkdir to create the directory
        if [ -d "$dirpath" ]; then
            echo "Directory created: $dirpath"
        else
            echo "Failed to create directory."
        fi
    fi

elif [ "$operation" = "delete" ]; then
    read -p "Enter the directory path: " dirpath

    if [ -d "$dirpath" ]; then
        read -p "Enter the backup directory path: " backup_dirpath

        if [ -d "$backup_dirpath" ]; then     #checking if a directory exists, using `-d`
            
            # Create a backup with the date of deletion
            backup_filename="$(basename "$dirpath")_$(date +%Y%m%d)"
            backup_path="$backup_dirpath/$backup_filename"
            cp -r "$dirpath" "$backup_path"  # `-r` does the command recursively ie; subdirectories okke aa reqd pathilekku store aavum

            if [ -d "$backup_path" ]; then
                echo "Directory backed up as $backup_filename in $backup_dirpath."

               
                rm -r "$dirpath"   # Deleting the directory with rm; -r does the command recursively ie; subdirectories and folders um okke eduthu kalayum
                if [ ! -d "$dirpath" ]; then
                    echo "Directory deleted: $dirpath"  
                else
                    echo "Failed to delete directory."
                fi
            else
                echo "Failed to create backup directory."
            fi
        else
            echo "Backup directory does not exist."
        fi
    else
        echo "Directory does not exist."
    fi

else
    echo "Invalid operation."
fi

 
