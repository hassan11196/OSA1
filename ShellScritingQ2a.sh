
read -p "Enter your Mail : " username

read -s -p "Enter your Password : " password
# Disables inputs echos to screen
echo -e "\nMy Mails\n"
curl -u $username:$password --silent "https://mail.google.com/mail/feed/atom" |  grep -oPm1 "(?<=<title>)[^<]+" | sed '1d'