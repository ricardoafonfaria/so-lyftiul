#!/bin/bash
{
echo '
<html>
<head>
<meta charset="UTF-8">
<title>Estatísticas LyftIUL</title>
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
</head>
<body>
<div class="col-12">
<h1 class="text-center" >Condutores</h1>
<table style="border-collapse: separate; border-spacing: 4px" class="table table-striped table-borderless table-hover">
  <thead class="bg-primary text-white">
    <tr style="text-align:left">
      <th class="rounded-top" width="15%" scope="col">#</th>
      <th class="rounded-top" width="25%" scope="col">Nome</th>
      <th class="rounded-top" width="15%" scope="col">Viagens</th>
      <th class="rounded-top" width="15%" scope="col">Pontos</th>
      <th class="rounded-top" width="15%" scope="col">Rating</th>
      <th class="rounded-top" width="15%" scope="col">Saldo</th>
    </tr>
  </thead>
  <tbody>'

cat ~/trabalho/condutores.txt | awk -F: '{print "<tr><td>" $1 "</td><td>" $2 "</td><td>" $9 "</td><td>" $10 "</td><td>" int(($10/$9)+0.5) "</td><td>" $11 "</td></tr>"}'

echo '</tbody></table>
<h1 class="text-center" >Passageiros</h1>
<table style="border-collapse: separate; border-spacing: 4px" class="table table-striped table-borderless table-hover">
  <thead class="bg-primary text-white">
    <tr style="text-align:left">
      <th class="rounded-top" width="15%" scope="col">#</th>
      <th class="rounded-top" width="25%" scope="col">Nome</th>
      <th class="rounded-top" width="60%" scope="col">Turma</th>
    </tr>
  </thead>
  <tbody>'

cat ~/trabalho/passageiros.txt | awk -F: '{print "<tr><td>" $1 "</td><td>" $2 "</td><td>" $3 "</td></tr>"}'

echo '</tbody></table>
<h1 class="text-center" >Maus Condutores</h1>
<table style="border-collapse: separate; border-spacing: 4px" class="table table-striped table-borderless table-hover">
  <thead class="bg-primary text-white">
    <tr style="text-align:left">
      <th class="rounded-top" width="15%" scope="col">#</th>
      <th class="rounded-top" width="25%" scope="col">Nome</th>
      <th class="rounded-top" width="15%" scope="col">Viagens</th>
      <th class="rounded-top" width="15%" scope="col">Pontos</th>
      <th class="rounded-top" width="15%" scope="col">Rating</th>
      <th class="rounded-top" width="15%" scope="col">Saldo</th>
    </tr>
  </thead>
  <tbody>'

cat ~/trabalho/condutores.txt | awk -F: '{if (int(($10/$9)+0.5) < 5) print "<tr><td>" $1 "</td><td>" $2 "</td><td>" $9 "</td><td>" $10 "</td><td>" int(($10/$9)+0.5) "</td><td>" $11 "</td></tr>"}'

echo '</tbody></table>
</div>
</body>
<footer class="m-0">
<h6 class="text-center">Última atualização - '$(date +%H:%M:%S)'</h6>
</head>
</html>'
} > ~/public_html/stats.html
