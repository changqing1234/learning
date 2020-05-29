from keras.models import Sequential
from keras.layers import Dense, Dropout
from keras.optimizers import SGD
import tensorflow as tf
from keras.utils import to_categorical

mnist = tf.keras.datasets.mnist # 包含了很多数据集，第一次使用需要下载
(x_train, y_train), (x_test, y_test) = mnist.load_data()


y_train = to_categorical(y_train)
y_test = to_categorical(y_test)


x_train  = x_train.reshape(x_train.shape[0], 784)
x_test = x_test.reshape(x_test.shape[0], 784)


x_train = x_train.astype('float32')
x_test = x_test.astype('float32')

print(x_train[0])

x_train /=255
x_test /=255

model = Sequential()
model.add(Dense(256, input_shape=(784,), activation="relu"))
model.add(Dense(256, activation="relu"))
model.add(Dense(10, activation="softmax"))
model.summary()


print('trainning networking')
model.compile(loss='categorical_crossentropy',optimizer=SGD(0.01),metrics=['accuracy'])


history = model.fit(x_train,y_train,batch_size=100,epochs=10,verbose=2,validation_data=(x_test, y_test))
score = model.evaluate(x_test, y_test, verbose=0)
print('Test loss:', score[0])
print('Test accuracy:', score[1])
