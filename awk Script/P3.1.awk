BEGIN{
	printf "EMP_ID\tName\t\tLocation Designation\n";
	printf "--------------------------------------------\n";
}

($5=="Manager"){
	printf "\n"$1"\t"$2"\t"$3"\t"$4"\t"$5;
}

END{
	printf "\n";
}
