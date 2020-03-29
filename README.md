# APS1 - Board musician module
Students: Caio Fauza e Pedro Paulo Telho<br/>

## Abstract:
The project consists in create a musician module that works playing three different songs. Some functions were programmed to further user experience during the utilization of the product.
<p>These functions are:</p>
<ul>
  <li>STOP/PAUSE button;</li>
  <li>Next/Previous button;</li>
  <li>OLED display song name;</li>
  <li>Board led that shine at same music's rhythm</li>
</ul>

## Connections:
<p>OLED: <b>EXT1</b></p>
<p>Pins:</p>
<ul>
  <li>PA4: Buzzer</li>
  <li>PD28: Button 1 (OLED)</li>
  <li>PC31: Button 2 (OLED)</li>
  <li>PA11: Button 3 (BOARD)</li>
  <li>PC8: Board led </li>
  <li>PA0: LED 1 (OLED)</li>
  <li>PC30: LED 2 (OLED)</li>
  <li>PB2: LED 3 (OLED)</li>
</ul>

## Software structures:
The software was structured with flags applications that improves in our code efficiency and hardware utilization. First of all, we created a struct called music with two elements: song notes and period of song note. In addition, our logic was implemented in a simple way defining our songs as numbers. When next button is pressed, our code increment (++) in a variable and jump to the next song, the same logic is implemented on previous button, but decrementing (--). When module starts to play music, all LED's starts to shine at same music's rhythm and the OLED displays song name.
<br/>
<br/>

## Resumo:
O projeto consiste em criar um módulo musical que toca três músicas diferentes. Algumas funções foram programadas para melhorar a experiência do usúario durante a utilização do produto.
<p>Essas funções são:</p>
<ul>
  <li>STOP/PAUSE botão;</li>
  <li>Next/Previous botão;</li>
  <li>OLED mostra nome da música;</li>
  <li>Led da placa que acende e apaga no ritmo da música</li>
</ul>

## Conexões:
<p>OLED: <b>EXT1</b></p>
<p>Pinos:</p>
<ul>
  <li>PA4: Buzzer</li>
  <li>PD28: Botão 1 (OLED)</li>
  <li>PC31: Botão 2 (OLED)</li>
  <li>PA11: Botão 3 (BOARD)</li>
  <li>PC8: Led da placa </li>
  <li>PA0: LED 1 (OLED)</li>
  <li>PC30: LED 2 (OLED)</li>
  <li>PB2: LED 3 (OLED)</li>
</ul>

## Estrutura do software:
O software foi estruturado com a utilização de flags para melhorar a eficiência do código e a utilização do hardware. Primeiramente, criamos uma "struct" chamada "music" com dois elementos: as notas das músicas e o período de toque dessas músicas. Além diss, nossa lógica foi implementada de maneira simples, definindo nossas músicas como números. Cada vez que o botão de pular música for pressionado, é adicionada uma unidade (++) a variável, assim o hardware interpreta o jump da música. Da mesma forma ocorre para o botão de voltar, porém, decrementando uma unidade (--). Quando o módulo começa a tocar uma música, todos os LED's da placa começam a piscar no mesmo ritmo da música e o nome da música é apresentado no OLED.

