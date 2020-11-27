alpha - transparency  
rgb - colors  
  
normalizar os valores ARGB pra 0 - 1, fazer as operacoes com ARGB, no final tudo q for menor q 0 vira 0 e tudo maior q 1 vira 1, ai converte de novo pra 0 -255 ou hexadecimal direto
  
Pra transformar ARGB num int vc usa bitwise operators. Um int tem 4 bytes, cada byte tem 8 bits. Com 8 bits vc consegue escrever 255 em binário. Ou seja, em um int vc tem bits o suficiente pra armazenar os 4 números q vao de 0 a 255. Para colocar todos os valores no mesmo número vc usa bitwise operatos q fazem um shift nos valores. 0000...A vira 0000...A...0000, q vira 0000...AR, e assim por diante até ocupar todo o espaço.
