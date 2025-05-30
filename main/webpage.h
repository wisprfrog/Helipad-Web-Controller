const char MAIN_page[] PROGMEM = R"rawliteral( 
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="icon" href="data:," />
    <link rel="stylesheet" href="style.css" />

    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link
      href="https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100..900;1,100..900&family=Winky+Sans:ital,wght@0,300..900;1,300..900&display=swap"
      rel="stylesheet"
    />

    <style>
      :root{
    font-family: 'Roboto', sans-serif;
    font-size: 15px;

    --principal: #2a9236;
    --text-white: #fff;
    --button_color: #ff2222;
}

body{
  width: 412px;
  height: 912px;
  background-color: var(--principal);
  padding: 0;
  margin: 0;
  position: relative;
  top: -80px;
}

.flex_row{
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: center;
}

.flex_column{
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}

@media (max-width: 600px) {
  .title{
    color: var(--text-white);
    font-size: 1.5rem;
    margin: 3rem 0 2rem 0;
  }

  .helipuerto{
    /* background-color: red; */
    width: 23rem;
    height: 23rem;
  
    align-content: space-around;
    margin-bottom: 2rem;
  }
  
  .circulo{
    width: 70%;
    height: 70%;
  }
  
  .fondo{
    position: absolute;
  }

  #circulo_grande{
    width: 100%;
    height: 100%;
    transform: rotate(60deg);
    z-index: 2;
  }
  
  #circulo_mediano{
    /* background-color: green; */
    transform: rotate(45deg);
    z-index: 3;
  }
  
  #circulo_peque{
    transform: rotate(75deg);
    z-index: 4;
  }
  
  #h_central{
    /* background-color: grey; */
    background-position: center;
    z-index: 5;
  }

  .buttons{
    width: 99%;
    flex-wrap: wrap;
    justify-content: space-evenly;
    row-gap: 1.5rem;
  }

  .buttons a{
    width: 30%;
  }

  .button{
    font-weight: 700;
    color: var(--text-white);
    width: 100%;
    padding: 1rem 0;
    border: 1px solid var(--button_color);
    background-color: var(--button_color);
    border-radius: 1rem;
  }

  .button_off{
    --button_color: #ff2222;
  }

  .button_on{
    --button_color: #25e72c;
  }
}
    </style>
  </head>
  <body class="flex_column" style="row-gap: 2rem">
    <h1 class="title flex_row">PANEL DE CONTROL DE HELIPUERTO</h1>
    <section class="helipuerto flex_row">
      <div class="flex_column" id="circulo_grande">
        <svg
          class="fondo"
          width="130%"
          height="130%"
          viewBox="0 0 240 240"
          xmlns="http://www.w3.org/2000/svg"
        >
          <g transform="translate(120,120)" fill="none" stroke-width="8">
            <!-- Boton encendido: /circ_grande_x/on     boton apagado: /circ_grande_x/off -->
            <!-- Color encendido: #f5fa0b               color apagado: #f5fa0bA6 -->

            <!-- Arco de 57°: punto final aproximadamente en (54.5, 83.2) -->
            <a href="%url_circ_grande_4%">
              <path
                d="M 100 0 A 100 100 0 0 1 54.5 83.2"
                stroke="%color_circ_grande_4%"
              />
            </a>

            <!-- Segundo arco, rotado 72° -->
            <a href="%url_circ_grande_5%">
              <g transform="rotate(72)">
                <path
                  d="M 100 0 A 100 100 0 0 1 54.5 83.2"
                  stroke="%color_circ_grande_5%"
                />
              </g>
            </a>

            <!-- Tercer arco, rotado 144° -->
            <a href="%url_circ_grande_1%">
              <g transform="rotate(144)">
                <path
                  d="M 100 0 A 100 100 0 0 1 54.5 83.2"
                  stroke="%color_circ_grande_1%"
                />
              </g>
            </a>

            <!-- Cuarto arco, rotado 216° -->
            <a href="%url_circ_grande_2%">
              <g transform="rotate(216)">
                <path
                  d="M 100 0 A 100 100 0 0 1 54.5 83.2"
                  stroke="%color_circ_grande_2%"
                />
              </g>
            </a>

            <!-- Quinto arco, rotado 288° -->
            <a href="%url_circ_grande_3%">
              <g transform="rotate(288)">
                <path
                  d="M 100 0 A 100 100 0 0 1 54.5 83.2"
                  stroke="%color_circ_grande_3%"
                />
              </g>
            </a>
          </g>
        </svg>

        <div class="circulo flex_column" id="circulo_mediano">
          <svg
            class="fondo"
            width="120%"
            height="120%"
            viewBox="0 0 240 240"
            xmlns="http://www.w3.org/2000/svg"
          >
            <g transform="translate(120,120)" fill="none" stroke-width="12">
              <!-- Boton encendido: /circ_med_x/on     boton apagado: /circ_med_x/off -->
              <!-- Color encendido: #f5fa0b               color apagado: #f5fa0bA6 -->

              <!-- Primer arco de 60° -->
              <a href="%url_circ_med_4%">
                <path
                  d="M 100 0 A 100 100 0 0 1 50.0 86.6"
                  stroke="%color_circ_med_4%"
                />
              </a>

              <!-- Segundo arco, rotado 90° -->
              <a href="%url_circ_med_1%">
                <g transform="rotate(90)">
                  <path
                    d="M 100 0 A 100 100 0 0 1 50.0 86.6"
                    stroke="%color_circ_med_1%"
                  />
                </g>
              </a>

              <!-- Tercer arco, rotado 180° -->
              <a href="%url_circ_med_2%">
                <g transform="rotate(180)">
                  <path
                    d="M 100 0 A 100 100 0 0 1 50.0 86.6"
                    stroke="%color_circ_med_2%"
                  />
                </g>
              </a>

              <!-- Cuarto arco, rotado 270° -->
              <a href="%url_circ_med_3%">
                <g transform="rotate(270)">
                  <path
                    d="M 100 0 A 100 100 0 0 1 50.0 86.6"
                    stroke="%color_circ_med_3%"
                  />
                </g>
              </a>
            </g>
          </svg>

          <div class="circulo flex_column" id="circulo_peque">
            <svg
              class="fondo"
              width="120%"
              height="120%"
              viewBox="0 0 100 110"
              xmlns="http://www.w3.org/2000/svg"
            >
              <!-- Boton encendido: /circ_peq_x/on     boton apagado: /circ_peq_x/off -->
              <!-- Color encendido: #f5fa0b               color apagado: #f5fa0bA6 -->

              <!-- Primer arco superior -->
              <a href="%url_circ_peq_2%">
                <path
                  d="M 20,50 A 30,30 0 0,1 80,50"
                  stroke="%color_circ_peq_2%"
                  stroke-width="6"
                  fill="none"
                />
              </a>

              <!-- Segundo arco inferior con menos separación, siguiendo la trayectoria circular -->
              <a href="%url_circ_peq_1%">
                <path
                  d="M 20,60 A 30,30 0 0,0 80,60"
                  stroke="%color_circ_peq_1%"
                  stroke-width="6"
                  fill="none"
                />
              </a>
            </svg>

            <div class="circulo flex_column" id="h_central">
              <svg
                class="fondo"
                width="40%"
                height="40%"
                viewBox="0 0 50 50"
                xmlns="http://www.w3.org/2000/svg"
              >
                <!-- Boton encendido: /letra_h/on     boton apagado: /letra_h/off -->
                <!-- Color encendido: #ffffff         color apagado: #ffffffA6 -->

                <a href="%url_letra_h%">
                  <text
                    x="10"
                    y="40"
                    font-family="Arial"
                    font-size="40"
                    font-weight="600"
                    fill="%color_letra_h%"
                  >
                    H
                  </text>
                </a>
              </svg>
            </div>
          </div>
        </div>
      </div>
    </section>

    <section class="flex_row buttons">
      <!-- Boton encendido: /name/on     boton apagado: /name/off  -->
      <!-- Clase encencido: button_on    clase apagado: button_off -->

      <a href="%url_boton_heli%">
        <button class="button %clase_boton_heli%">HELIPUERTO</button>
      </a>

      <a href="%url_boton_sec1%">
        <button class="button %clase_boton_sec1%">SECUENCIA 1</button>
      </a>

      <a href="%url_boton_sec2%">
        <button class="button %clase_boton_sec2%">SECUENCIA 2</button>
      </a>

      <a href="%url_boton_sec3%">
        <button class="button %clase_boton_sec3%">SECUENCIA 3</button>
      </a>

      <a href="%url_boton_sec4%">
        <button class="button %clase_boton_sec4%">SECUENCIA 4</button>
      </a>

      <a href="%url_boton_sec5%">
        <button class="button %clase_boton_sec5%">SECUENCIA 5</button>
      </a>
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

    
)rawliteral";