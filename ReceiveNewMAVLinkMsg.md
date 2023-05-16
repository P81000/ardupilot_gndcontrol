# _Recieve a new mavlink message_

# - libraries > GCS_MAVLink > GCS.h
1. Declarar uma função para lidar  com a nova mensagem recebida.

# - ArduPlane > GCS_Mavlink.cpp
1. Definir a função declarada no GCS.h.

# - libraries > GCS_MAVLink > GCS_Common.cpp 
## > Na função 'ap_message GCS_MAVLINK::mavlink_id_to_ap_message_id(const uint32_t mavlink_id) const' 
1. Adicionar ao map a relação da  mensagem recebida e seu ID.

# - libraries > GCSMAVLink > ap_message.h
1. Adicionar uma variável ao enum para não precisar lidar com o ID, sempre respeitando o MSG_LAST.

## > Na função 'bool GCS_MAVLINK::try_send_message(const enum ap_message id)'
1. Adicionar um novo caso de uso.

# *O nome das variáveis devem ser os mesmos em todas as partes do código* 
