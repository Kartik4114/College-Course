*version 9.1 1964610330
u 222
U? 5
DSTM? 3
? 12
@libraries
@analysis
.TRAN 1 0 0 0
+0 0.5ms
+1 16ms
.OPT 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
DIGINITSTATE 0
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 4270 
@status
n 0 124:01:19:10:33:47;1708319027 e 
s 2832 124:03:29:01:59:00;1714336140 e 
*page 1 0 970 720 iA
@ports
port 71 HI 410 320 v
port 85 HI 440 50 d
port 165 HI 230 110 h
port 166 HI 240 190 h
@parts
part 61 DigClock 190 170 h
a 0 u 0 0 0 20 hln 100 ONTIME=.5mS
a 0 u 0 0 0 30 hln 100 OFFTIME=.5mS
a 0 x 0:13 0 0 0 hln 100 PKGREF=INPUT
a 1 xp 9 0 0 -2 hln 100 REFDES=INPUT
part 130 7408 470 90 h
a 0 sp 11 0 40 50 hln 100 PART=7408
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP14
a 0 s 0:13 0 0 0 hln 100 GATE=A
a 0 a 0:13 0 0 0 hln 100 PKGREF=U4
a 0 ap 9 0 40 0 hln 100 REFDES=U4A
part 2 7476 260 150 h
a 0 sp 11 0 40 70 hln 100 PART=7476
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP16
a 0 s 0:13 0 0 0 hln 100 GATE=A
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
a 0 ap 9 0 40 -2 hln 100 REFDES=U1A
part 3 7476 410 150 h
a 0 sp 11 0 40 70 hln 100 PART=7476
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP16
a 0 a 0:13 0 0 0 hln 100 PKGREF=U2
a 0 x 0:13 0 0 0 hln 100 GATE=B
a 0 xp 9 0 40 -2 hln 100 REFDES=U2B
part 4 7476 570 150 h
a 0 sp 11 0 40 70 hln 100 PART=7476
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP16
a 0 s 0:13 0 0 0 hln 100 GATE=A
a 0 a 0:13 0 0 0 hln 100 PKGREF=U3
a 0 ap 9 0 40 -2 hln 100 REFDES=U3A
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 217 nodeMarker 200 170 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=8
part 218 nodeMarker 340 150 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=9
part 220 nodeMarker 470 150 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=10
part 221 nodeMarker 630 150 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=11
@conn
w 73
a 0 up 0:33 0 0 0 hln 100 LVL=
s 290 210 290 220 72
s 290 220 290 320 74
s 290 320 410 320 75
s 410 320 440 320 77
s 600 320 600 220 79
s 440 210 440 220 81
s 440 320 600 320 84
a 0 up 33 0 520 319 hct 100 LVL=
s 440 220 440 320 83
w 87
a 0 up 0:33 0 0 0 hln 100 LVL=
s 290 120 290 60 86
s 290 60 440 60 88
s 440 60 440 50 90
s 440 120 440 60 92
s 440 60 600 60 96
a 0 up 33 0 520 59 hct 100 LVL=
s 600 60 600 120 98
w 161
a 0 up 0:33 0 0 0 hln 100 LVL=
s 540 190 570 190 155
s 540 150 540 190 153
s 540 100 540 150 149
a 0 up 33 0 542 125 hlt 100 LVL=
s 540 150 570 150 151
s 570 150 580 150 34
w 168
s 230 110 250 110 167
s 250 110 250 150 169
s 250 150 260 150 171
s 260 150 270 150 173
w 175
a 0 up 0:33 0 0 0 hln 100 LVL=
s 240 190 260 190 174
a 0 up 33 0 250 189 hct 100 LVL=
w 12
a 0 up 0:33 0 0 0 hln 100 LVL=
s 570 170 580 170 27
s 410 170 420 170 22
s 190 170 200 170 62
s 200 170 260 170 112
a 0 up 33 0 235 169 hct 100 LVL=
s 200 170 200 260 110
s 200 260 390 260 113
s 390 260 390 170 115
s 390 170 410 170 117
s 390 260 550 260 120
s 550 170 570 170 124
s 550 260 550 170 122
w 108
a 0 up 0:33 0 0 0 hln 100 LVL=
s 410 150 420 150 109
s 410 190 380 190 125
s 380 150 410 150 129
s 380 190 380 150 127
s 350 150 380 150 147
s 350 90 350 150 145
s 350 90 470 90 135
a 0 up 33 0 410 89 hct 100 LVL=
s 320 150 340 150 163
s 340 150 350 150 219
w 138
a 0 up 0:33 0 0 0 hln 100 LVL=
s 470 110 470 150 139
a 0 up 33 0 472 130 hlt 100 LVL=
@junction
j 260 150
+ p 2 J
+ w 168
j 260 190
+ p 2 K
+ w 175
j 240 190
+ s 166
+ w 175
j 230 110
+ s 165
+ w 168
j 410 150
+ p 3 J
+ w 108
j 410 190
+ p 3 K
+ w 108
j 470 150
+ p 3 Q
+ w 138
j 470 110
+ p 130 B
+ w 138
j 470 90
+ p 130 A
+ w 108
j 320 150
+ p 2 Q
+ w 108
j 380 150
+ w 108
+ w 108
j 350 150
+ w 108
+ w 108
j 570 170
+ p 4 CLK
+ w 12
j 570 150
+ p 4 J
+ w 161
j 600 220
+ p 4 \CLR\
+ w 73
j 600 120
+ p 4 \PRE\
+ w 87
j 570 190
+ p 4 K
+ w 161
j 410 170
+ p 3 CLK
+ w 12
j 260 170
+ p 2 CLK
+ w 12
j 190 170
+ p 61 1
+ w 12
j 200 170
+ w 12
+ w 12
j 390 260
+ w 12
+ w 12
j 290 120
+ p 2 \PRE\
+ w 87
j 440 50
+ s 85
+ w 87
j 440 120
+ p 3 \PRE\
+ w 87
j 440 60
+ w 87
+ w 87
j 540 100
+ p 130 Y
+ w 161
j 540 150
+ w 161
+ w 161
j 290 220
+ p 2 \CLR\
+ w 73
j 410 320
+ s 71
+ w 73
j 440 220
+ p 3 \CLR\
+ w 73
j 440 320
+ w 73
+ w 73
j 200 170
+ p 217 pin1
+ w 12
j 340 150
+ p 218 pin1
+ w 108
j 470 150
+ p 220 pin1
+ p 3 Q
j 470 150
+ p 220 pin1
+ w 138
j 630 150
+ p 221 pin1
+ p 4 Q
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
