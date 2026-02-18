import cv2

class MovementDetector:
    def __init__(self, video_source, sensitivity=30, min_area=1000):
        """Initialize the detector with video source and settings."""
        self.cap = cv2.VideoCapture(video_source)
        self.sensitivity = sensitivity
        self.min_area = min_area
        self.background_frame = None
        
        # Grab the first frame to set as background
        ret, frame = self.cap.read()
        if ret:
            self.background_frame = self._preprocess(frame)

    def _preprocess(self, frame):
        """Internal method to convert frame to gray and blur it."""
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        return cv2.GaussianBlur(gray, (21, 21), 0)

    def detect(self, frame):
        """Returns True if movement is detected in the current frame."""
        current_gray = self._preprocess(frame)
        
        # Calculate difference
        diff = cv2.absdiff(self.background_frame, current_gray)
        thresh = cv2.threshold(diff, self.sensitivity, 255, cv2.THRESH_BINARY)[1]
        thresh = cv2.dilate(thresh, None, iterations=2)
        
        # Find contours
        contours, _ = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        
        movement_found = False
        for contour in contours:
            if cv2.contourArea(contour) > self.min_area:
                movement_found = True
                break
                
        return movement_found, thresh

# --- Main Program Execution ---
detector = MovementDetector("glass_video.mp4")

while True:
    ret, frame = detector.cap.read()
    if not ret:
        break

    is_moving, debug_view = detector.detect(frame)

    if is_moving:
        cv2.putText(frame, "MOVEMENT DETECTED", (20, 50), 
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    cv2.imshow("Original Feed", frame)
    cv2.imshow("Threshold (Debug)", debug_view)

    if cv2.waitKey(30) & 0xFF == ord('q'):
        break

detector.cap.release()
cv2.destroyAllWindows()