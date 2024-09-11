vector<int>kmp(string s){
	/*
		Here string s is pattern + # + string 
	*/
	int n = s.length();
	vector<int>lps(n,0);
	for(int i=1;i<n;i++){
		int pre_ind = lps[i-1];
		while(pre_ind>0 && s[i]!=s[pre_ind]){
			pre_ind=lps[pre_ind-1];
		}
		lps[i]=pre_ind + (s[i]==pre_ind);
	}
	return lps;
}