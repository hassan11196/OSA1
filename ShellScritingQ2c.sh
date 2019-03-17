echo -e "\n Checking Numbers From 1 to 999 for sum of cubes"
num=1
for i in {1..999}
do
    sum=0
    p=$num
    while [[ $p -ne 0 ]]
    do
        ((tmp=$p%10))
        ((p=$p/10))
        ((q=$tmp*$tmp*$tmp))
        ((sum=$sum+$q))
    done

    if [[ $sum -eq $num ]]
    then
        echo $num
    fi
    ((num=$num+1))
done