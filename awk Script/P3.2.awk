BEGIN{
	printf "EMP_ID\tName\t\tSpecialization\tLocation\n";
	printf "------------------------------------------------\n";
}

($7=="Java"){
	if($4=="Delhi" || $4=="Pune"){
		printf "\n"$1"\t"$2"\t"$3"\t"$7"\t\t"$4;
	}
}

END{
	printf "\n";
}
