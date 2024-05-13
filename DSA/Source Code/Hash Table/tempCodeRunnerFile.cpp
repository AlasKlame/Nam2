 else{
        for (int i = companyName.length() - 20 ; i < companyName.length(); i++) {
            hash += ((int)companyName[i] * static_cast<long long>(pow(31,i)))  ;
        }
    }