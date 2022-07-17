void contas_timestamp(char *pt, log_t  log_novo){

    char *ano, *mes, *dia, *tempo, *h, *m, *s;
    int segundos,horas, minutos;

    pt = strtok(NULL," ");
      tempo = strtok(NULL," ");
      
      //pegando a data
      ano = strtok(pt,"-");
      mes = strtok(NULL,"-");
      dia = strtok(NULL,"-");
      strcpy(log_novo.data,ano);
      strcat(log_novo.data,"/");
      strcat(log_novo.data,mes);
      strcat(log_novo.data,"/");
      strcat(log_novo.data,dia);
      
      //pegando o tempo
      h = strtok(tempo,":");
      horas = atoi(h);
      horas = horas*3600;
      m = strtok(NULL,":");
      minutos = atoi(m);
      minutos = minutos*60;
      s = strtok(NULL,":");
      segundos = atoi(s); 
      log_novo.tempo = horas+minutos+segundos;
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

double processando_altitude(log_t  log_novo, log_t log_velho){

  double alt;
  if (log_novo.sub_acumulada > log_velho.sub_acumulada && log_velho.sub_acumulada > 0){
    alt = log_novo.sub_acumulada - log_velho.sub_acumulada;
  }

  return alt;
}

double processando_speed(log_t  log_novo, log_t log_velho){
   if (log_velho.vel_max < log_novo.vel_max){
    return log_novo.vel_max;
  }
}

int processando_heart_rate(log_t  log_novo, log_t log_velho){
  if (log_velho.hr_max < log_novo.hr_max){
    return log_novo.hr_max;
}

int processando_cadence(log_t  log_novo, log_t log_velho, contadores_t *cont ){

  int dif_segundo, cad;

  dif_segundo =  log_novo.tempo - log_velho.tempo;
  cad = log_velho.cad * dif_segundo;
  if (log_novo.cad != 0){
    cont.cont_segundos_cad += dif_segundo; 
  }

  return cad; 

}

double processando_speed_med(log_t  log_novo, log_t log_velho, contadores_t *cont){

  int dif_segundo;
  double vel_med;

  dif_segundo =  log_novo.tempo - log_velho.tempo;
  vel_med = log_velho.vel_max * dif_segundo;
  if (log_novo.vel_max != 0){
    cont.cont_segundos_vel += dif_segundo; 
  }

  return vel_med; 

}

int processando_heart_rate_med(log_t  log_novo, log_t log_velho, contadores_t *cont){
   int dif_segundo, hr_med;

  dif_segundo =  log_novo.tempo - log_velho.tempo;
  hr_med = log_velho.hr_max * dif_segundo;
  if (log_novo.hr_max != 0){
    cont.cont_segundos_hr += dif_segundo; 
  }

  return hr_med; 
}

void processando_dados(Bicicleta_t *bikes, int aux,log_t  log_novo, log_t log_velho, contadores_t *cont){

  double vel_med;
  int cad, hr;

  bikes[aux].informacoes[bikes[aux].cont_log].sub_acumulada += processando_altitude(log_novo,log_velho);
  bikes[aux].informacoes[bikes[aux].cont_log].vel_max = processando_speed(log_novo,log_velho);
  bikes[aux].informacoes[bikes[aux].cont_log].hr_max = processando_heart_rate(log_novo,log_velho);

  vel_med += processando_speed_med(log_novo,log_velho,cont);
  cad += processando_cadence(log_novo,log_velho,cont);
  hr += processando_heart_rate_med(log_novo,log_velho,cont);

  bikes[aux].informacoes[bikes[aux].cont_log].vel_med = vel_med/cont.cont_segundos_vel;
  bikes[aux].informacoes[bikes[aux].cont_log].cad = cad/cont.cont_segundos_cad;
  bikes[aux].informacoes[bikes[aux].cont_log].hr_med = hr/cont.cont_segundos_hr;

}

void le_bloco_de_log(char *line, log_t  log_novo, FILE *arq){

    while (line != "\n"){

        if (!strcmp(pt,"timestamp")){
            lendo_timestamp(*pt, log_novo)
        }
        
        if (!strcmp(pt,"distance")){
         log_novo.distance = lendo_distance( *pt);
        }

        if (!strcmp(pt,"heart_rate")){
            log_novo.hr_max = lendo_heart_rate( *pt);
        }

        if (!strcmp(pt,"speed")){
            log_novo.vel_max = lendo_speed( *pt);
        }

        if (!strcmp(pt,"altitude")){
            log_novo.sub_acumulada = lendo_altitude( *pt);
        }

        if (!strcmp(pt,"cadence")){
            log_novo.cadence = lendo_cadence( *pt);
        }

        fgets (line, LINESIZE, arq);   // tenta ler a próxima linha
    }

}

void adicionar_log(Bicicleta_t *bikes, int aux, char *arquivo, FILE *arq, contadores_t *cont){

    strcpy(bikes[aux].informacoes[bikes[aux].cont_log].nome_log,arquivo);
    char *line = malloc (sizeof(char)*LINESIZE);

    log_t  log_novo, log_velho;

    fgets (line, LINESIZE, arq);
    le_bloco_de_log(line, log_velho, arq);
    while (! feof (arq)){
      le_bloco_de_log(line, log_novo);
      processando_dados(bikes,aux,log_novo, log_velho, cont);
      log_velho = log_novo;
      fgets (line, LINESIZE, arq);   //lendo a próxima linha
    }

    bikes[aux].informacoes[bikes[aux].cont_log].distance = log_velho.distance;    

    free(line);


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