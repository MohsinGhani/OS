zenity --forms --title="Profil Info" \
--text="Enter Your Profile info" \
--separator="," \
--add-entry="Name" \
--add-password="Password" \
--add-entry="Email" \
--add-calendar="DOB">>record.csv

case $? in
0) echo "ok your Record is successfully insert";;
*) echo "Cancle";;
esac
