# Trabalho Avaliativo 1
- Nome: Augusto Ramos Molina
- Turma: M1 
- Email: armolina@inf.ufpel.edu.br
- Discord: gut0rm

## Caracterização do Problema

O problema resolvido foi o número 748 do LeetCode, chamado Shortest Completing Word, que pede o seguinte:

Dada uma string ```licensePlate``` e um array de strings ```words```, retornar a menor palavra aceitável. Para uma palavra ser aceitável ela deve conter todas as letras em ```licensePlate```, ignorando números e espaços e tratando letras como case insensitive. Se uma letra aparecer mais de uma vez, isso deve ocorrer em ```words[i]``` também.

## Casos testados com sucesso

| chave | array | saída |
|-|-|-|
| "1s3 PSt" | "step","steps","stripe","stepple" | "steps" |
| "1s3 456" | "looks","pest","stew","show" | "pest" |
| "2a3 Bd5" | "art", "abduct", "abide", "blank" | "abide" |

## O que está funcionando

O código passou tanto no **run** quanto no **submit** do LeetCode. Acredito que não há nenhum caso onde não funcione.
