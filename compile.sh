clear; clear;
if gcc Main.c Function.c -o matrix; then

	echo "Compile successful";
	ls matrix;
	echo "Run Program? Enter <y/n> : "; 
	read ans;
	if [[ $ans == "y" ]] 
	then
		./matrix;
	else
		echo "Program not executed";
	fi
else
	echo "Compile failed";
fi

