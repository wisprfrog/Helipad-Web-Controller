<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="icon" href="data:," />
    <link rel="stylesheet" href="style.css" />

    <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100..900;1,100..900&family=Winky+Sans:ital,wght@0,300..900;1,300..900&display=swap" rel="stylesheet">
  </head>
  <body class="flex_column" style=" row-gap: 2rem;">
    <h1 class="title flex_row">PANEL DE CONTROL DE HELIPUERTO</h1>
    <section class="helipuerto flex_row">
      <div class="flex_column" id="circulo_grande">
        <svg class="fondo" width="115%" height="115%" viewBox="0 0 240 240" xmlns="http://www.w3.org/2000/svg">
          <g transform="translate(120,120)" fill="none" stroke-width="8">
            <!-- Arco de 57°: punto final aproximadamente en (54.5, 83.2) -->
            <path d="M 100 0 A 100 100 0 0 1 54.5 83.2" stroke="#f5fa0bA6"/>
        
            <!-- Segundo arco, rotado 72° -->
            <g transform="rotate(72)">
              <path d="M 100 0 A 100 100 0 0 1 54.5 83.2" stroke="#f5fa0bA6"/>
            </g>
        
            <!-- Tercer arco, rotado 144° -->
            <g transform="rotate(144)">
              <path d="M 100 0 A 100 100 0 0 1 54.5 83.2" stroke="#f5fa0bA6"/>
            </g>
        
            <!-- Cuarto arco, rotado 216° -->
            <g transform="rotate(216)">
              <path d="M 100 0 A 100 100 0 0 1 54.5 83.2" stroke="#f5fa0bA6"/>
            </g>
        
            <!-- Quinto arco, rotado 288° -->
            <g transform="rotate(288)">
              <path d="M 100 0 A 100 100 0 0 1 54.5 83.2" stroke="#f5fa0bA6"/>
            </g>
          </g>
        </svg>        

        <div class="circulo flex_column" id="circulo_mediano">
          <svg class="fondo" width="115%" height="115%" viewBox="0 0 240 240" xmlns="http://www.w3.org/2000/svg">
            <g transform="translate(120,120)" fill="none" stroke-width="12">
              <!-- Primer arco de 60° -->
              <path d="M 100 0 A 100 100 0 0 1 50.0 86.6" stroke="#f5fa0bA6"/>
          
              <!-- Segundo arco, rotado 90° -->
              <g transform="rotate(90)">
                <path d="M 100 0 A 100 100 0 0 1 50.0 86.6" stroke="#f5fa0bA6"/>
              </g>
          
              <!-- Tercer arco, rotado 180° -->
              <g transform="rotate(180)">
                <path d="M 100 0 A 100 100 0 0 1 50.0 86.6" stroke="#f5fa0bA6"/>
              </g>
          
              <!-- Cuarto arco, rotado 270° -->
              <g transform="rotate(270)">
                <path d="M 100 0 A 100 100 0 0 1 50.0 86.6" stroke="#f5fa0bA6"/>
              </g>
            </g>
          </svg>

          <div class="circulo flex_column" id="circulo_peque">
            <svg class="fondo" width="130%" height="130%" viewBox="0 0 100 110" xmlns="http://www.w3.org/2000/svg">
              <!-- Primer arco superior -->
              <path d="M 20,50 A 30,30 0 0,1 80,50" stroke="#f5fa0b" stroke-width="6" fill="none"/>
              
              <!-- Segundo arco inferior con menos separación, siguiendo la trayectoria circular -->
              <path d="M 20,60 A 30,30 0 0,0 80,60" stroke="#f5fa0bA6" stroke-width="6" fill="none"/>
            </svg>

            <div class="circulo flex_column h_off" id="h_central">
              <svg class="fondo" width="65%" height="65%" viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                <text x="10" y="40" font-family="Arial" font-size="40" font-weight="600" fill="#ffffffA6">H</text>
              </svg>
            </div>
          </div>
        </div>
      </div>
    </section>
    
    <section class="flex_row buttons %STATE_HELI%">
      <button class="button button_off">
        HELIPUERTO
      </button>
      <button class="button button_off">
        SECUENCIA 1
      </button>
      
      <button class="button button_on">
        SECUENCIA 2
      </button>
      <button class="button button_off">
        SECUENCIA 3
      </button>
      <button class="button button_off">
        SECUENCIA 4
      </button>
      <button class="button button_off">
        SECUENCIA 5
      </button>
    </section>
  </body>
</html>

<!-- <p>HELIPUERTO (%STATE1%)</p>
    %BUTTON1%

    <p>SECUENCIA 1 (%STATE2%)</p>
    %BUTTON2%

    <p>SECUENCIA 2 (%STATE3%)</p>
    %BUTTON3%

    <p>SECUENCIA 3 (%STATE4%)</p>
    %BUTTON4%

    <p>SECUENCIA 4 (%STATE5%)</p>
    %BUTTON5%

    <p>SECUENCIA 5 (%STATE6%)</p>
    %BUTTON6% -->
