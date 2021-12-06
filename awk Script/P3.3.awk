BEGIN{
	printf "EMP_ID\tName\t\tLocation Designation\tJoining_Month\tJoining_Year\n";
	printf "----------------------------------------------------------------------------\n";
}

($10>=2000 && $10<=2005){	
	if($9=="Jan" && $10=="2000");
	else if($9=="Dec" && $10=="2005");
	else
		print $1"\t"$2"\t"$3"\t"$4"\t "$5"\t"$9"\t\t"$10;
}

END{
	printf "\n";
}
