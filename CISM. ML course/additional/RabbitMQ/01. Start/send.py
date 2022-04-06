import pika

rabbit_url = 'localhost'
connection = pika.BlockingConnection(pika.URLParameters(rabbit_url))
channel = connection.channel()
channel.queue_declare(queue='hello')
channel.basic_publish(exchange='',
                      routing_key='hello',
                      body='Hello World!')
print(" [x] Sent 'Hello World!'")
connection.close()