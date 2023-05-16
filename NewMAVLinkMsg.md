# _Send a new mavlink message_
# - modules > mavlink > message_definitions > v1.0 > ardupilotmega.xml
1. Adicionar um novo campo message  seguindo o padrão utilizado  pelo código.

# - ArduPlane > GCS_Mavlink.cpp
1. Contém os grupos de mensagens a  serem enviadas via MAVLink,  adicionar uma nova mensagem em um  grupo existente ou criar um novo  grupo.

# - libraries > GCSMAVLink > ap_message.h
1. Adicione o nome da mensagem  inserida no GCS ao final da lista  enum, sempre respeitando o MSG_LAST.

# - libraries > GCS_MAVLink > GCS.h
1. Adicionar uma função para lidar  com a nova mensagem a ser enviada.

# - libraries > GCS_MAVLink > GCS_Common.cpp 
## > Na função 'ap_message GCS_MAVLINK::mavlink_id_to_ap_message_id(const uint32_t mavlink_id) const' 
1. Adicionar ao map a relação da  mensagem a ser enviada e seu ID.

## > ... Qualquer lugar do código
1. Declarar a implementação da funcão  definida no GCS.h para enviar  a mensage.

## > Na função 'bool GCS_MAVLINK::try_send_message(const enum ap_message id)'
1. Adicionar um novo caso de uso.

# *O nome das variáveis devem ser os mesmos em todas as partes do código* 
