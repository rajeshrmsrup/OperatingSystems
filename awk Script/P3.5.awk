BEGIN{
	mx=0;
}
($4=="Delhi" && $6>mx){
	tmp=$0;
	mx=$6;	
}

END{
	printf tmp"\n";
}
