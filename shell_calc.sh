echo -e "\nShell_calc Script arguments : $1 and $2"
num1=$1
num2=$2
sum=$(($1+$2))
sub=$(($1-$2))
mul=$(($1*$2))
div=$(($1/$2))

echo "Sum of $1 and $2 = $sum"
echo "Difference of $1 and $2 = $sub"
echo "Product of $1 and $2 = $mul"
echo "Quotient of $1 and $2 = $div"