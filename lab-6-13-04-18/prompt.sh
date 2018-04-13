var=`zenity --entry --text="enter value"`
echo "value is $var"

zenity --info --title="Hello" --text="$var"
