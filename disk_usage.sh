if [ $# -lt 1 ]
then
    echo "NO Directory given as argument. Exiting"
    exit 1
else
    dir=$1
    if [ -d $dir ]
    then
        echo "Directory Exists"
        if [ $# -eq 2 ]
        then 
                num=$2
        else
            num=10
        fi
        cd $dir
        sudo du -a  $dir | sort -n -r | head -n $num
    else
        echo "Directory does NOT exist. Exiting"
        exit 1
    fi
fi