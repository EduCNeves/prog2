void contas_timestamp(char *pt, log_t  aux_dados){

    char *ano, *mes, *dia, *tempo, *h, *m, *s;
    int segundos,horas, minutos;

    pt = strtok(NULL," ");
      tempo = strtok(NULL," ");
      
      //pegando a data
      ano = strtok(pt,"-");
      mes = strtok(NULL,"-");
      dia = strtok(NULL,"-");
      strcpy(aux_dados.data,ano);
      strcat(aux_dados.data,"/");
      strcat(aux_dados.data,mes);
      strcat(aux_dados.data,"/");
      strcat(aux_dados.data,dia);
      
      //pegando o tempo
      h = strtok(tempo,":");
      horas = atoi(h);
      horas = horas*3600;
      m = strtok(NULL,":");
      minutos = atoi(m);
      minutos = minutos*60;
      s = strtok(NULL,":");
      segundos = atoi(s); 
      aux_dados.tempo = horas+minutos+segundos;
}

int lendo_distance(char *pt){

    int distance;
    pt = strtok(NULL," ");
    distance = atof(pt);
    return (distance/1000);

}

int lendo_heart_rate(char *pt){
    
    int hr
    
    pt = strtok(NULL," ");
    hr = atof(pt);
    return hr;

    if (aux_dados.hr_max < hr){
        aux_dados.hr_max = hr;
    }
}

int lendo_speed(char *pt){
    double vel;
    pt = strtok(NULL," ");
    vel = atof(pt);
    return vel*3.6;
      /*
      if (flag == 1){
        vel_velho = vel;
        flag = 0;
      }
      else {
        vel = atof(pt);
      }

      vel = vel*3.6;
      if (bikes[aux].informacoes[bikes[aux].cont_log].vel_max < vel){
          bikes[aux].informacoes[bikes[aux].cont_log].vel_max = vel;
      }

      vel_velho = vel;*/
}

int lendo_altitude(char *pt){

    double alt;
    pt = strtok(NULL," ");
    alt = atof(pt);
    return alt_novo;  
    /*
      if (flag == 1){
        alt_velho = alt_novo;
        flag = 0;
      }
      else{
        alt_novo = atof(pt);
      }  
      if (alt_novo > alt_velho && alt_velho > 0){
        bikes[aux].informacoes[bikes[aux].cont_log].sub_acumulada += alt_novo - alt_velho;
      }
      alt_velho = alt_novo;
    }*/

}

int lendo_cadence(char *pt){

    int cad;
    pt = strtok(NULL," ");
    cad = atof(pt);
    return cad;
      /*
      if (flag == 1){
        cad_velha = cad;
        flag = 0;
      }
      else {
        cad = atof(pt);
      }

      cad_velha = cad;*/
}

// processando_distance(log_novo){}
processando_altitude(){}
processando_cadence(){

  

}
processando_heart_rate(){}
processando_speed(){}
processando_speed_med(){}
processando_heart_rate_med(){}

void processando_dados(log_novo, log_velho){

  // processando_distance(){}
  processando_cadence(){}


}

le_bloco_de_log(){

    while (line != "\n"){

        if (!strcmp(pt,"timestamp")){
            processando_timestamp(char *pt, log_t  aux_dados)
        }
        
        if (!strcmp(pt,"distance")){
         aux_dados.distance = processando_distance(char *pt);
        }

        if (!strcmp(pt,"heart_rate")){
            aux_dados.hr_max = processando_heart_rate(char *pt);
        }

        if (!strcmp(pt,"speed")){
            aux_dados.vel_max = processando_speed(char *pt);
        }

        if (!strcmp(pt,"altitude")){
            aux_dados.sub_acumulada = processando_altitude(char *pt);
        }

        if (!strcmp(pt,"cadence")){
            aux_dados.cadence = processando_cadence(char *pt);
        }

        fgets (line, LINESIZE, arq);   // tenta ler a próxima linha
    }

}

void adicionar_log(Bicicleta_t *bikes, int aux, char *arquivo, FILE *arq){

    strcpy(bikes[aux].informacoes[bikes[aux].cont_log].nome_log,arquivo);
    char *line = malloc (sizeof(char)*LINESIZE);

    log_t  log_novo, log_velho;
    fgets (line, LINESIZE, arq);
    le_bloco_de_log(line, log_velho, arq);
    while (! feof (arq)){
      le_bloco_de_log(line, log_novo);
      processando_dados(log_novo, log_velho);
      log_velho = log_novo;
      fgets (line, LINESIZE, arq);   // tenta ler a próxima linha
        
    }

}


void adicionar_log(Bicicleta_t *bikes, int aux, char *arquivo, FILE *arq){

  strcpy(bikes[aux].informacoes[bikes[aux].cont_log].nome_log,arquivo);

  char *line = malloc (sizeof(char)*LINESIZE);
  int i,cad_velha,cad_medio,cad,hr_velho,hr_medio;
  char *pt, *ano, *mes, *dia, *tempo, *h, *m, *s;
  int segundos,horas, minutos, hr,segundo_velho, segundos_atual, dif_segundo, cont_segundos;
  double distance,vel,alt_novo,alt_velho, vel_medio, vel_velho;

  log_t  aux_dados;

  fgets (line, LINESIZE, arq) ;
  while (! feof (arq)){
    
    pt = strtok(line, ": ");

    if (!strcmp(pt,"timestamp")){
      
      processando_timestamp(char *pt, log_t  aux_dados)


      //media de velhocidade
      segundo_velho = bikes[aux].informacoes[bikes[aux].cont_log].tempo;
      segundos_atual = segundos;
      
      if (segundo_velho == 0){
        dif_segundo = 1;
      }
      else{
        dif_segundo = segundos_atual - segundo_velho;
      }

      bikes[aux].informacoes[bikes[aux].cont_log].tempo = segundos;

      //velocidade media
      if (vel_velho != 0 ){
        vel_medio += vel_velho * dif_segundo;
        cont_segundos +=  dif_segundo;
      }

      //cadencia medio
      if (cad_velha != 0 ){
        cad_medio += cad_velha * dif_segundo;
        cont_segundos +=  dif_segundo;
      }

      //hr medio
      if (hr_velho != 0 ){
        hr_medio += hr_velho * dif_segundo;
        cont_segundos +=  dif_segundo;
      }



    }

    if (!strcmp(pt,"distance")){
      aux_dados.distance = processando_disntandcia(char *pt);
    }

    if (!strcmp(pt,"heart_rate")){
      pt = strtok(NULL," ");

      if (flag == 1){
        hr = atof(pt);
        hr_velho = hr;
        flag = 0;
      }
      else {
        hr = atoi(pt);
      }

      if (bikes[aux].informacoes[bikes[aux].cont_log].hr_max < hr){
          bikes[aux].informacoes[bikes[aux].cont_log].hr_max = hr;
      }
    }

    if (!strcmp(pt,"speed")){
      pt = strtok(NULL," ");
      
      if (flag == 1){
        vel = atof(pt);
        vel_velho = vel;
        flag = 0;
      }
      else {
        vel = atof(pt);
      }

      vel = vel*3.6;
      if (bikes[aux].informacoes[bikes[aux].cont_log].vel_max < vel){
          bikes[aux].informacoes[bikes[aux].cont_log].vel_max = vel;
      }

      vel_velho = vel;

    }

    if (!strcmp(pt,"altitude")){
      pt = strtok(NULL," ");
      if (flag == 1){
        alt_novo = atof(pt);
        alt_velho = alt_novo;
        flag = 0;
      }
      else{
        alt_novo = atof(pt);
      }  
      if (alt_novo > alt_velho && alt_velho > 0){
        bikes[aux].informacoes[bikes[aux].cont_log].sub_acumulada += alt_novo - alt_velho;
      }
      alt_velho = alt_novo;
    }
    
    if (!strcmp(pt,"cadence")){
      pt = strtok(NULL," ");
      
      if (flag == 1){
        cad = atof(pt);
        cad_velha = cad;
        flag = 0;
      }
      else {
        cad = atof(pt);
      }

      cad_velha = cad;

    }

    fgets (line, LINESIZE, arq);   // tenta ler a próxima linha
    i++ ;
    //flag = 0;
  }

  bikes[aux].informacoes[bikes[aux].cont_log].vel_med = vel_medio/cont_segundos;
  bikes[aux].informacoes[bikes[aux].cont_log].hr_max = hr_medio/cont_segundos;
  bikes[aux].informacoes[bikes[aux].cont_log].cad = cad_medio/cont_segundos;


  bikes[aux].cont_log++;

  free(line);

}