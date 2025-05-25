*version 9.1 3997773817
u 64
U? 3
DSTM? 6
? 6
@libraries
@analysis
.TRAN 1 0 0 0
+0 0
+1 2s
+3 0.5s
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
pageloc 1 0 2986 
@status
n 0 124:00:15:11:06:42;1705297002 e 
s 0 124:01:19:10:45:23;1708319723 e 
*page 1 0 970 720 iA
@ports
@parts
part 3 7486 270 120 h
a 0 sp 11 0 40 50 hln 100 PART=7486
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP14
a 0 s 0:13 0 0 0 hln 100 GATE=A
a 0 a 0:13 0 0 0 hln 100 PKGREF=U2
a 0 ap 9 0 40 0 hln 100 REFDES=U2A
part 2 7408 270 220 h
a 0 sp 11 0 40 50 hln 100 PART=7408
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=DIP14
a 0 s 0:13 0 0 0 hln 100 GATE=A
a 0 a 0:13 0 0 0 hln 100 PKGREF=U1
a 0 ap 9 0 40 0 hln 100 REFDES=U1A
part 6 STIM1 130 130 h
a 0 a 0:13 0 0 0 hln 100 PKGREF=DSTM3
a 0 ap 9 0 1 -2 hln 100 REFDES=DSTM3
a 0 u 0 0 0 100 hln 100 COMMAND3=2s 0
a 0 u 0 0 0 70 hln 100 TIMESTEP=0.5s
a 0 u 0 0 0 80 hln 100 COMMAND1=1s 0
a 0 u 0 0 0 90 hln 100 COMMAND2=1.5s 1
part 7 STIM1 130 160 h
a 0 a 0:13 0 0 0 hln 100 PKGREF=DSTM4
a 0 ap 9 0 1 -2 hln 100 REFDES=DSTM4
a 0 u 0 0 0 70 hln 100 TIMESTEP=1s
a 0 u 0 0 0 90 hln 100 COMMAND2=1s 1
a 0 u 0 0 0 100 hln 100 COMMAND3=1.5s 0
a 0 u 0 0 0 110 hln 100 COMMAND4=2s 1
a 0 u 0 0 0 120 hln 100 COMMAND5=2.5s 0
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 45 nodeMarker 160 160 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=2
part 43 nodeMarker 170 130 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=1
part 47 nodeMarker 360 130 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=U2A:Y
a 0 a 0 0 4 22 hlb 100 LABEL=4
part 46 nodeMarker 360 230 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=U1A:Y
a 0 a 0 0 4 22 hlb 100 LABEL=3
@conn
w 18
s 100 120 100 130 17
w 53
a 0 sr 0 0 0 0 hln 100 LABEL=SUM
a 0 up 0:33 0 0 0 hln 100 LVL=
s 360 130 340 130 52
a 0 sr 3 0 350 128 hcn 100 LABEL=SUM
a 0 up 33 0 350 129 hct 100 LVL=
w 58
a 0 sr 0 0 0 0 hln 100 LABEL=CARRY
a 0 up 0:33 0 0 0 hln 100 LVL=
s 340 230 360 230 59
a 0 sr 3 0 350 228 hcn 100 LABEL=CARRY
a 0 up 33 0 350 229 hct 100 LVL=
s 360 230 370 230 63
w 10
a 0 up 0:33 0 0 0 hln 100 LVL=
a 0 sr 0 0 0 0 hln 100 LABEL=A
s 130 130 170 130 14
a 0 sr 3 0 150 128 hcn 100 LABEL=A
s 130 130 120 130 11
s 270 130 270 120 15
s 190 130 270 130 40
s 190 130 190 220 38
a 0 up 33 0 192 175 hlt 100 LVL=
s 190 220 270 220 41
s 170 130 190 130 44
w 27
a 0 up 0:33 0 0 0 hln 100 LVL=
a 0 sr 0 0 0 0 hln 100 LABEL=B
s 130 160 160 160 26
a 0 sr 3 0 145 158 hcn 100 LABEL=B
s 270 160 270 140 28
s 160 160 270 160 32
s 160 160 160 240 30
s 160 240 270 240 33
a 0 up 33 0 215 239 hct 100 LVL=
s 270 240 280 240 35
@junction
j 130 160
+ p 7 pin1
+ w 27
j 160 160
+ w 27
+ w 27
j 270 240
+ p 2 B
+ w 27
j 190 130
+ w 10
+ w 10
j 270 220
+ p 2 A
+ w 10
j 170 130
+ p 43 pin1
+ w 10
j 160 160
+ p 45 pin1
+ w 27
j 270 120
+ p 3 A
+ w 10
j 270 140
+ p 3 B
+ w 27
j 340 130
+ p 3 Y
+ w 53
j 360 130
+ p 47 pin1
+ w 53
j 340 230
+ p 2 Y
+ w 58
j 360 230
+ p 46 pin1
+ w 58
j 130 130
+ p 6 pin1
+ w 10
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
