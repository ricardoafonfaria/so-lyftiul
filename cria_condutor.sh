#!/bin/bash
if [[ $# = 8 ]] ; then
	if grep --quiet "^$1" condutores.txt; then
		echo "Erro! Condutor já inscrito."
	else
		echo "$1:$2:$3:$4:$5:$6:$7:$8:0:0:0" >> condutores.txt
		echo "Condutor inscrito com sucesso!"
	fi
else
	echo "Número errado de argumentos, tente de novo."
fi
