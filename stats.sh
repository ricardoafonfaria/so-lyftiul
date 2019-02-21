#!/bin/bash
ncondutores=`cat condutores.txt | wc -l`
npassageiros=`cat passageiros.txt | wc -l`
saldototal=`cat condutores.txt | awk -F "[:]" 'BEGIN{s=0} {s=s+$11} END{print s}'`
toppontos=`cat condutores.txt | sort -t ":" -nrk10 | head -5 | awk -F "[:]" '{ print $2 , "-" , $10 }'`
toprating=`cat condutores.txt | awk -F "[:]" '{print $2 , "-" , int(($10/$9)+0.5)}' | sort -t "-" -nrk2 | head -3`
ige=`cat condutores.txt | grep ":I[A-D][0-9]" | wc -l`
eti=`cat condutores.txt | grep ":ET[A-D][0-9]" | wc -l`
lei=`cat condutores.txt | grep ":EI[A-D][0-9]" | wc -l`

echo "Condutores: $ncondutores, Passageiros: $npassageiros"
echo
echo "Soma do saldo dos condutores: $saldototal"
echo
echo "Top 5 - Condutores com mais pontos:
$toppontos"
echo
echo "Top 3 - Condutores com mais rating:
$toprating"
echo
echo "Condutores por curso:"
echo "IGE - $ige, ETI - $eti, LEI - $lei"
