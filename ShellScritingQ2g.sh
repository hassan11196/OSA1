

echo -e "\nAll files in current directory : \n"
for file in *.*
do 
    echo -e "\nname : $file"
    if [ -r $file ]
    then
        echo "$file has READ permission."
    else
        echo "#file does NOT have READ permission."
    fi 
    if [ -w $file ]
    then
        echo "$file has WRITE permission."
    else
        echo "#file does NOT have WRITE permission."
    fi
    if [ -x $file ]
    then
        echo "$file has execute permission."
    else
        echo "#file does NOT have execute permission."
    fi


done