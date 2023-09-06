// PASAR DE SEGUNDOS A HMS

void func_hora(int *hora, int *min, int *seg){
    *hora = (*seg)%3600;
    *seg -= (*hora)*3600;
    *min = (*seg)%60;
    *seg -= (*min)*60;
}