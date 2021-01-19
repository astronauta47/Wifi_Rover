import cv2 as cv

camView = cv.VideoCapture(0)

while(True):

	# Capture the video frame by frame
	ret, frame = camView.read()
	
	# Display the resulting frame
	cv.imshow('frame', frame)
	
	# ESCAPE button for quit
	if cv.waitKey(1) & 0xFF == 27:
		break
		
camView.release()
cv.destroyAllWindows()