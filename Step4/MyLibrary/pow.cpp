int pow(int x, int y){
    int ret = 1;
    for (int i = 0; i < y; i++){
        ret *= x;
    }
    return ret;
}
