bool repeatedSubstringPattern(char * s){
    int i = 1;
    int l = strlen(s);
    int x = 0;
    while(i <= l/2){
        x =0;
        if(l%i == 0){
            while(x < l){
                if(s[x%i] != s[x]){
                    break;
                }
                x++;
            }
            if(x == l){
                return 1;
            }
        }
        i++;
        
    }
    return 0;
}
