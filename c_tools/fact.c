int fact(int x){
    int result=1;
    while(x>1){
        result*=x;
        x--;
    }
    return result;
}
