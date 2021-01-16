int main()
{
    double x, xn, fd, h;
    x = 2.0;
    h = 0.0001;
    while(1) {
    printf("x=%lf¥n",x);
    fd = (f(x+h)-f(x))/h;
    xn = x - f(x)/fd;
        if(fabs(xn-x) < 0.00001){
        break;
        } else {
        x = xn;
        }
    }
    printf("answer=%lf¥",xn);
    return 0;
}