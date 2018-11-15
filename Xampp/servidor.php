<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Painel de Controle</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script src="./jquery.js"></script>
    <script src="./js.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.4.0/Chart.min.js"></script>
</head>
<body>
        <div class="chart-container" style="width: 85%">
                <canvas id="myChart"></canvas>
            </div>
        <table>
                <tr>
                    <td><select id="carga" onchange="newGraph()">
                        <option value="Total">Total</option>
                        <option value="C1">Carga 1</option>
                        <option value="C2">Carga 2</option>
                        <option value="C3">Carga 3</option>
                        <option value="C4">Carga 4</option>
                        <option value="C5">Carga 5</option>
                        <option value="C6">Carga 6</option>
                        <option value="C7">Carga 7</option>
                        <option value="C8">Carga 8</option>
                        <option value="C9">Carga 9</option>
                        <option value="C10">Carga 10</option>
                        </select></td>
                    <td><select id="informacao" onchange="newGraph()">
                        <option value="C1">Consumo</option>
                        <option value="C2">Corrente</option>
                        <option value="C3">Tensão</option>
                        </select></td>
                </tr>
            </table>
            <p>Fator de Potência: <span id="fp"></span></p>
            <p>Tensão: <span id="tensao"></span></p>
            <p>Corrente: <span id="corrente"></p>    
</body>
</html>