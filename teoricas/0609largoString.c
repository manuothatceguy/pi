int longString(const char *s){ //Ver cuan largo es un string
    int dim = 0;
    while(*s++) // si es 0 llegué al fin. '0' es NULL o la direc 0000h
        ++dim;
    return dim;
}