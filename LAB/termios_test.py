import termios
import tty
import sys

# 터미널 설정 가져오기
old_settings = termios.tcgetattr(sys.stdin)

# 비동기 모드로 변경
tty.setcbreak(sys.stdin.fileno())

while True:
    # 사용자의 입력을 처리
    ch = sys.stdin.read(1)
    if ch == 'a':
        print("a key is pressed")
    elif ch == 'b':
        print("b key is pressed")
    else:
        print("unknown key is pressed")

# 기존 터미널 설정 복원
termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)
