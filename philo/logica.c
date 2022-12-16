/*
    Resumo do projeto filósofos: Basicamente uma simulação do uso de threads, que deve impedir
    situações de deadlocks ou data races, usando uma obstração de filósofos(threads) numa mesa, 
    que precisam comer para evitar morrer, cada filósofo precisa de dois garfos para comer
    porém a quantidade de garfos é a mesma da de filósofos, os garfos representam mutexes.
    Eles devem evitar morrer, caso algum morra o programa acaba.
    
    -Ideia do programa eles precisam ficar intercalando o uso dos garfos o que representa o acesso a
    uma parte crítica do programa(variáveis ou dados que podem causar data races). Por isso os garfos
    precisam ser implementados como mutexes.

    -Pegar os dois garfos é a parte sensível do programa que pode causar deadlocks.
    -Eles precisam pegar os dois garfos para iniciarem sua ação de comer e não morrerem.
*/
