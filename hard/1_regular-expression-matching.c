char* rearrange(char* p) {
	// "_***" -> "_*"
	// ".*_*" -> ".*"
	// "_*_*" -> "_*"
	int l_p = strlen(p), l_after, i = 0;
	char re_p[l_p+1], prev;
	do {
		l_p = strlen(p);
		while (*p != '\0') {
	    	if (*p == '*') {
	    		// "_*****" -> "_*"
	    		while(*(p+1) == '*') ++p;
	    		// "_*_"
	    		prev = re_p[i-1];
	    		while (prev == '.' && *(p+1) != '\0' && *(p+2) == '*') p += 2; // ".*_*" -> ".*"
	    		while(*(p+1) == prev) {
	    			if (*(p+2) == '*') { // "_*_*" -> "_*"
	                    p += 2;
	                    continue;
	    			}
	    			else { //"_*_" -> "__*"
	    				re_p[i] = prev;
	                    ++i;
	                    ++p;
	                    continue;
	    			}
	    		}
	    		re_p[i] = '*';
	    		++i;
	    		++p;
	    	}
	    	else {
	            re_p[i] = *p;
	            ++i;
	            ++p;
	        }
	    }
	    re_p[i] = '\0';
		l_after = i;
		i = 0;
		p = re_p;
	}while (l_after < l_p);
	char* out = (char*)malloc(l_after+1);
	strcpy(out, re_p);
	return out;
}

bool isMatch(char* s, char* p) {
    p = rearrange(p);
    int count = 0, skip; // count the number _* being used.
    char* ptr,* start = p,* start_s = s;
    while (*s != '\0') {
        if (*p == '\0') return false;
        
        // counter ".*", process backward
        if (*p == '.' && *(p+1) == '*') {
            p += 2;
            while (*s != '\0') {
                while (*s != '\0' && *s != *p) ++s;
                if (*s == '\0') return isMatch(s, p);
                else if (isMatch(s, p) == false) ++s;
                else return true;
            }
        }
        
        if (*p == '.' && p-start > 1 && *(p-1) == '*') {
            //case 352//"b*.b"->"bb*b" -> "bbb*"
            char new_p[strlen(start)+1];
            strncpy(new_p, start, (int)(p-start));
            new_p[p - start] = *(p-2);
            new_p[p - start+1] = '\0';
            strcat(new_p, p+1);
            if (isMatch(start_s, new_p) == true) return true;
        }
        if (*(p+1) == '*') {
            if (*s != *p && *p != '.') {
                
                if (count == 0) { // _* not being used, delete it
                    char new_p[strlen(start)+1];
                    strncpy(new_p, start, (int)(p-start));
                    new_p[p - start] = '\0';
                    strcat(new_p, p+2);
                    return isMatch(start_s, new_p);
                    /*
                    if (isMatch(start_s, new_p) == true) return true;
                    else {
                        skip = (int)(p-start);
                        start = rearrange(new_p);
                        p = start + skip;
                    }*/
                }
                else {
                    p += 2;
                    count = 0;
                }
            }
            else {
                ++count;
                ++s;
            }
        }
        else {
            if (*s != *p && *p != '.') return false;
            else {
                ++s;
                ++p;
            }
        }

    }
    if (*p != '\0' && *(p+1) == '*' && count != 0) p += 2;

    // delete "." left
    if (*p == '.' && p-start > 1 && *(p-1) == '*') {
        //case 352//"b*.b"->"bb*"
        char new_p[strlen(start)+1];
        strncpy(new_p, start, (int)(p-start));
        new_p[p - start] = *(p-2);
        new_p[p - start+1] = '\0';
        strcat(new_p, p+1);
        if (isMatch(start_s, new_p) == true) return true;
    }

    // delete _* left
    while (*p != '\0' && *(p+1) == '*') {
    	char new_p[strlen(start)+1];
        strncpy(new_p, start, (int)(p-start));
        new_p[p - start] = '\0';
        strcat(new_p, p+2);
        return isMatch(start_s, new_p);
    }
    
    if (*p == '\0') return true;
    else return false;
}
