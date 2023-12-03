// Metodo que verifica si un string es un numero
bool isNumber(string str) {
  for(int i=0; i<str.length(); i++) {
    if(!isdigit(str[i])) {return false;}
  }
  return true;
}

// Metodo que verifica si un string es un float (Si el string tiene más de un punto: 1.1.1 igual pasará, lo cuál sería un error)
bool isFloat(string str) {
  for(int i=0; i<str.length(); i++) {
    if(str[i]!='.'){
      if(!isdigit(str[i])) {return false;}
    }
  }
  return true;
}