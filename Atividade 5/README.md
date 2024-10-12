Faça um programa em C que leia o número N de elementos de um vetor V. Após isso, leia os N elementos de V. O programa deve ordenar todos os subvetores de V utilizando os métodos Shell Sort e Quick Sort. Para cada subvetor de V, deve-se imprimir qual método fez menos operações (comparação + cópias), imprimindo Q quando for o Quick Sort, S quando for o Shell Sort e o caractere hífen quando o número de contagens for igual. O Shell deve utilizar os gaps no formato 2^k - 1, e o Quick Sort deve utilizar o elemento do meio como pivô.

Por exemplo, considere o seguinte vetor V: [3, 6, 5, 2]. Os subvetores de V são: V1: [3], V2: [3, 6], V3: [3, 6, 5], e V4 = [3, 6, 5, 2]. Para V1, o número de operações é o mesmo para os dois métodos. Para V2, V3 e V4, o Shell Sort realiza menos operações. Portanto, seu programa deve imprimir: -SSS