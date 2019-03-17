read -p "Enter name of File1 : " FILE
read -p "Enter name of File2 : " FILE2
if [ -f $FILE ]
then
    echo "$FILE exists."
    if [ -r $FILE ]
    then
        echo "$FILE allows reading."
        if [ -f $FILE2 ]
        then 
            echo "$FILE2 exists"
            read -p "Do you want to overwrite $FILE2 ? (Y/N)" n 
            if [[ $n = 'y' || $n = 'Y' ]]
            then
                cat $FILE > $FILE2
                echo "$FILE is copied into $FILE2"
                exit 0
            else
                echo "Exiting Script without copying"
                exit 1

            fi
        else
            echo "$FILE2 does not exists"
            cat $FILE > $FILE2
            echo "$FILE is copied into $FILE2"
            exit 0
        fi

    else
        echo "$FILE does not allow reading. Please Set Permissions"
        exit 1
    fi

    # sed stands for stream editor
   
else
    echo "File $FILE does not exist in current directory."
fi