std::string s= "abcabc";
	int len = s.length();
        int next[len+1];
        next[0] = -1;
        int j = 0, k = -1;
        
        while( j<len )
        {
            if( k==-1 || s[j]==s[k] )
                next[++j] = ++k;
            else k = next[k];
        }
		// for(int i=0;i<=len;i++)
		// {
		// 	std::cout<<next[i]<<std::endl;
		// }
		if(next[len]%(len-next[len]) == 0)
		{
			std::cout<< len-(len-next[len])<<std::endl;
		}
		else
			std::cout<<len<<std::endl;
