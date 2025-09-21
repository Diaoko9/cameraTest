# This Python file uses the following encoding: utf-8

import glob
import cv2
import tensorflow
from sklearn.preprocessing import LabelBinarizer
import numpy as np
from sklearn.model_selection import train_test_split
from keras import layers, models


def loadData(dataset):
    images=[]
    labels = []

    for item in glob.glob(dataset):
            img = cv2.imread(item)
            img = cv2.resize(img, (32, 32))  # Conformed
            img = img / 255.0  # Normalization
            images.append(img)
            label = item.split("\\")[-2]
            labels.append(label)


            images = np.array(images)
        # print(images)
            lb = LabelBinarizer()
            labels = lb.fit_transform(labels)
            # print(labels)

            X_train, X_test, y_train, y_test = train_test_split(images, labels,
                                                                    test_size=0.2, random_state=42)
            return X_train, X_test, y_train, y_test

def cnnModel():


    cnnModel = models.Sequential([
        layers.Conv2D(32, (3, 3), activation="relu", padding="same",
                              input_shape=(32, 32, 3)),
        layers.MaxPool2D((2, 2)),
        layers.Conv2D(64, (3, 3), activation="relu", padding="same"),
        layers.MaxPool2D((2, 2)),
        layers.Flatten(),
        layers.Dense(32, activation="relu"),
        layers.Dense(9, activation="softmax")
    ])
    cnnModel.compile(loss="categorical_crossentropy", optimizer='sgd',
                    metrics=["accuracy"]
                             )
    return cnnModel

cnn = cnnModel()
print(cnn.summary())

# if __name__ == "__main__":
#     pass
