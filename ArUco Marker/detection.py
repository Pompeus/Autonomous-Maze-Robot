import cv2 as cv
from cv2 import aruco
import numpy as np

marker_dict = aruco.Dictionary_get(aruco.DICT_4X4_50)
param_markers = aruco.DetectorParameters_create()
cap = cv.VideoCapture(1)

# Configurando a resolução da câmera para 1920x1080
cap.set(cv.CAP_PROP_FRAME_WIDTH, 1920)
cap.set(cv.CAP_PROP_FRAME_HEIGHT, 1080)

# Lista para armazenar as posições do marcador ao longo do tempo
path = []

# Variável para salvar o vídeo
fourcc = cv.VideoWriter_fourcc(*'XVID')
out = cv.VideoWriter('tracking/trajeto.avi', fourcc, 20.0, (640, 480))

# Criando uma janela em tela cheia
cv.namedWindow("frame", cv.WND_PROP_FULLSCREEN)
cv.setWindowProperty("frame", cv.WND_PROP_FULLSCREEN, cv.WINDOW_FULLSCREEN)

# Laço de repetição para a identificação do marcador
while True:
    ret, frame = cap.read()
    if not ret:
        break
    gray_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    marker_corners, marker_IDs, reject = aruco.detectMarkers(
        gray_frame, marker_dict, parameters=param_markers
    )
    if marker_corners:
        for ids, corners in zip(marker_IDs, marker_corners):
            cv.polylines(
                frame,
                [corners.astype(np.int32)],
                True,
                (0, 255, 255),
                4,
                cv.LINE_AA
            )
            # Calculando o centro do marcador
            center = tuple(map(int, np.mean(corners, axis=1).ravel()))
            # Adicionando a posição do centro do marcador atual à lista de caminho
            path.append(center)

    # Desenhando as linhas conectando os pontos do caminho
    if len(path) > 1:
        for i in range(1, len(path)):
            cv.line(frame, path[i - 1], path[i], (0, 0, 255), 2)

    # Salvando o quadro no vídeo
    out.write(frame)

    # Mostrando a janela de exibição do vídeo em tempo real
    cv.imshow("frame", frame)

    # Chave necessária para parar a gravação por meio da tecla "q"
    key = cv.waitKey(1)
    if key == ord("q"):
        break

# Salvando a última imagem do trajeto
if path:
    cv.imwrite("tracking/trajeto_completo.png", frame)

# Liberando a câmera e fechando a janela
cap.release()
cv.destroyAllWindows() 

