#!/bin/bash

# Function to create a directory
create_directory() {
    read -p "Enter the directory path: " dirpath

    # Check if the directory already exists
    if [ -d "$dirpath" ]; then
        echo "Directory already exists."
    else
        # Create the directory
        mkdir "$dirpath"
        if [ -d "$dirpath" ]; then
            echo "Directory created: $dirpath"
        else
            echo "Failed to create directory."
        fi
    fi
}

# Function to delete a directory and generate a backup
delete_directory() {
    read -p "Enter the directory path: " dirpath

    if [ -d "$dirpath" ]; then
        read -p "Enter the backup directory path: " backup_dirpath

        # Check if the backup directory exists
        if [ -d "$backup_dirpath" ]; then
       
            backup_filename="$(basename "$dirpath")_$(date +%Y%m%d)"
            backup_path="$backup_dirpath/$backup_filename"
            cp -r "$dirpath" "$backup_path"

            if [ -d "$backup_path" ]; then
                echo "Directory backed up as $backup_filename in $backup_dirpath."

                # Delete the directory
                rm -r "$dirpath"
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
}

# Main menu
while true; do
    echo "Select an option:"
    echo "1. Create directory"
    echo "2. Delete directory"
    echo "0. Exit"

    read -p "Enter your choice: " choice

    case $choice in
        1)
            create_directory
            ;;
        2)
            delete_directory
            ;;
        0)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac

    echo
done
