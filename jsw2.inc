;
; Code equates
;

OSWRCH		= PRINTCHAR
OSBYTE		= $FFF4

cheat		= 0		; 0 = no cheat
				; 1 = no hit
				; 2 = infinite lives

L0000		= $0000
L0001		= $0001
L0003		= $0003
L0004		= $0004		; Colour

L0010		= $0010
L0011		= $0011		; Time counter
L0012		= $0012
L0013		= $0013
L0014		= $0014
L0015		= $0015
L0016		= $0016
L003E		= $003E
L0041		= $0041
L0042		= $0042
L0043		= $0043
L0044		= $0044

hitflag		= $0045

L004C		= $004C
L004D		= $004D
L004E		= $004E
L0050		= $0050		; Room level address
L0051		= $0051

L0052		= $0052		; Level data pointer
L0053		= $0053
L0054		= $0054

L0055		= $0055		; Current Room nr

L0056		= $0056
L0057		= $0057		; Frame counter
L0058		= $0058
L0059		= $0059
L005A		= $005A
L005B		= $005B
L005C		= $005C
L005D		= $005D
L005E		= $005E
L005F		= $005F
L0060		= $0060
L0061		= $0061
L0062		= $0062
L0063		= $0063		; Death flag
L0064		= $0064
L0065		= $0065
L0066		= $0066
L0067		= $0067
L0068		= $0068
L0069		= $0069		; Jumponly flag
L006A		= $006A
L006B		= $006B
L006C		= $006C
L006D		= $006D
L006E		= $006E
L006F		= $006F

L0070		= $0070
L0071		= $0071
L0072		= $0072
L0073		= $0073
L0074		= $0074
L0075		= $0075
L0076		= $0076
L0077		= $0077
L0078		= $0078
L0079		= $0079
L007A		= $007A
L007B		= $007B
L007C		= $007C
L007D		= $007D
L007E		= $007E
L007F		= $007F

L0080		= $0080
L0081		= $0081
L0082		= $0082
L0083		= $0083
L0084		= $0084
L0085		= $0085
L0086		= $0086
L0087		= $0087		; Nr of sprites on screen
L0088		= $0088
L0089		= $0089
L008A		= $008A
L008B		= $008B		; Jump key flag
L008C		= $008C
L008D		= $008D
L008E		= $008E
L008F		= $008F		; Sound jumpflag

L0090		= $0090
L0091		= $0091
L0092		= $0092		; lb-Spritedata address
L0093		= $0093		; hb-Spritedata address
L0094		= $0094		; Nr of bytes to plot for sprite
L0095		= $0095
L0096		= $0096
L0097		= $0097
L0098		= $0098
L009A		= $009A

L009B		= $009B		; Lives

L009C		= $009C
L009D		= $009D		; Time's up flag
L009E		= $009E		; End of game flag
L009F		= $009F

L00FC		= $00FC

L0204	= $0204
L0205	= $0205

L0381		= $0381		; Controls
				; $00 = keyboard
				; $40 = Joystick keyboard
				; $80 = Joystick AtoMMC

L1111       = $1111

LFE00       = $FE00
LFE06       = $FE06
LFE07       = $FE07
LFE08       = $FE08
LFE09       = $FE09

;
; Start of code
;

;------------------------------------------------
L0400:
            jmp L048D              ; Build intro screen
;------------------------------------------------

;L0403:
;            lda #>L7998               ; A9 79
;            sta L0091              ; 85 91
;            lda #<L7998               ; A9 98
;            sta L0090              ; 85 90
;
;            lda #$00               ; A9 00
;            sta L0092              ; 85 92
;            ldx #$20               ; A2 20
;L0411:      ldy #$07               ; A0 07
;L0413:      asl L0092              ; 06 92
;            lda (L0090),Y          ; B1 90
;            rol A                  ; 2A
;            sta (L0090),Y          ; 91 90
;            bcc L041E              ; 90 02
;            inc L0092              ; E6 92
;L041E:      dey                    ; 88
;            bpl L0413              ; 10 F2
;            lda L0090              ; A5 90
;            sec                    ; 38
;            sbc #$08               ; E9 08
;            sta L0090              ; 85 90
;            bcs L042C              ; B0 02
;            dec L0091              ; C6 91
;L042C:      dex                    ; CA
;            bne L0411              ; D0 E2
;            rts                    ; 60
;
;L0430:
;            ldx #$00               ; A2 00
;            lda L0674,X            ; BD 74 06
;            sta L007B              ; 85 7B
;            ldy #$07               ; A0 07
;            lda #$20               ; A9 20
;            lsr L007B              ; 46 7B
;            bcc L0441              ; 90 02
;            lda #$4C               ; A9

;--------------------------------------------

L0440:      jmp L048D		; Display intro screen

;-------------------------------------------
; Scroll bottomline 1 pixel to the left
;-------------------------------------------

L0443:
	ldy #7			; Repeat for 8 lines
L0444:
	ldx scrolltab,y
	asl $961f,x
	rol $961e,x
	rol $961d,x
	rol $961c,x
	rol $961b,x
	rol $961a,x
	rol $9619,x
	rol $9618,x
	rol $9617,x
	rol $9616,x
	rol $9615,x
	rol $9614,x
	rol $9613,x
	rol $9612,x
	rol $9611,x
	rol $9610,x
	rol $960f,x
	rol $960e,x
	rol $960d,x
	rol $960c,x
	rol $960b,x
	rol $960a,x
	rol $9609,x
	rol $9608,x
	rol $9607,x
	rol $9606,x
	rol $9605,x
	rol $9604,x
	rol $9603,x
	rol $9602,x
	rol $9601,x
	rol $9600,x
	dey
	bpl L0444

	jsr $fe66		; Wait 1/60 sec

	rts

scrolltab:
	.byte $00,$20,$40,$60,$80,$a0,$c0,$e0


;--------------------------------------------
; Print Jet Set Willy 2 in intro screen
; Every bit set 1 is block
;--------------------------------------------

L0470:
	lda #$0A		; Cusor down 2 lines
	jsr OSWRCH
	jsr OSWRCH

            ldx #$00               ; A2 00
L0472:      lda L0674,X            ; BD 74 06
            sta L007B              ; 85 7B

            ldy #$07               ; A0 07

L0479:      lda #$20               ; A9 20
            lsr L007B              ; 46 7B
            bcc L0481              ; 90 02

            lda #127               ; A9 EF
L0481:      jsr OSWRCH              ; 20 EE FF
            dey                    ; 88
            bpl L0479              ; 10 F2

            inx                    ; E8
            cpx #$30               ; E0 30

            bne L0472              ; D0 E6

            rts                    ; 60

;--------------------------------------------
; Build intro screen
;--------------------------------------------

L048D:
; Set vars

            lda #$88               ; A9 80
            sta L004D              ; 85 4D
            lda #$10               ; A9 10
            sta L009B              ; 85 9B

; Clear screen

	jsr vdu12
            jsr L0470              ; 20 70 04

; Set text pointer to scroller

L049D:      lda #>L0530            ; Point to scrolltext5
            sta L0071              ; 85 71
            lda #<L0530               ; A9 30
            sta L0070              ; 85 70

            ldy #$00               ; A0 00
            sty L0072              ; 84 72
L04A9:      ldy L0072              ; A4 72

; Plot character at bottom right position

	lda #$20-1		; Set character entry at 31,22
	sta XPOS
	lda #$16
	sta YPOS

            lda (L0070),Y          ; B1 70
            jsr OSWRCH              ; 20 EE FF
            tax                    ; AA
            beq L04E5              ; F0 23

            lda #$07               ; A9 07
            sta L007B              ; 85 7B

L04C6:
            jsr L0443              ; Scroll bottomline
            dec L007B              ; C6 7B
            bne L04C6              ; D0 F4

            inc L0057              ; E6 57

            jsr L0512              ; 20 12 05

            jsr L0B15              ; Plot Willy for each live
            jsr L04FF              ; 20 FF 04

            inc L0072              ; E6 72
            bne L04A9              ; D0 C8

            inc L0071              ; E6 71
            bne L04A9              ; D0 C4

L04E5:      lda #$20               ; A9 80
L04E6:
            sta L0070              ; 85 70

L04E9:      lda L0070              ; A5 70
            and #$07               ; 29 07
            bne L04F2              ; D0 03
            jsr L0512              ; 20 12 05

L04F2:      jsr L04FF              ; 20 FF 04
            dec L0071              ; C6 71
            bne L04E9              ; D0 F0
            dec L0070              ; C6 70
            bne L04E9              ; D0 EC
            beq L049D              ; F0 9E
L04FF:
	bit L0381		; Scan controls
	bmi scan_joymmc
	bvs scan_joykey
	lda #$f0		; Reset matrix counter
	sta $b000

	jsr $fe71		; Scan key
	cpy #0                    ; 8A
            bne L0511              ; Return
	jmp L0510

scan_joymmc:
	jsr joyget
	and #$10
	beq L0511
	jmp L0510

scan_joykey:
	jsr $fe71
	cpy #9
	bne L0511

L0510:
            lda #$9c               ; A9 8C
            sta L004D              ; 85 4D

            pla                    ; 68
            pla                    ; 68
L0511:      rts                    ; 60

;--------------------------------------------

L0512:      dec L0527              ; CE 27 05
            bpl L051C              ; 10 05
            lda #$07               ; A9 07
            sta L0527              ; 8D 27 05
L051C:      ldx L0527              ; AE 27 05
            lda L0528,X            ; BD 28 05
            ora #$19               ; 09 19
            sta L0000                ; 85 00
            rts                    ; 60

;--------------------------------------------

L0527:      .byte $07
L0528:      .byte $26,$22,$24,$20,$24,$06,$02,$04

L0530:      .byte "...Jetset Willy II was "
            .byte "written by Chris Rob"
            .byte "son.....Jet Set Will"
            .byte "y II was prepared by"
            .byte " Tynesoft under lice"
            .byte "nce from Software Pr"
            .byte "ojects and is copyri"
            .byte "ght to Software Proj"
            .byte "ects.....You must gu"
            .byte "ide Willy to collect"
            .byte " all the items aroun"
            .byte "d the house before m"
            .byte "idnight so that Mari"
            .byte "a will let him go to"
            .byte " bed......Press SPAC"
            .byte "E to start the game."
            .byte $00

;------------------------------------------------
; Jet Set Willy 2 letters intro screen
; Every bit is a character
;------------------------------------------------

L0674:
	.byte $70,$77,$EE,$0E
	.byte $20,$21,$22,$04
	.byte $20,$27,$EE,$04
	.byte $20,$21,$28,$04
	.byte $30,$27,$EE,$04
	.byte $00,$00,$00,$00
	.byte $00,$00,$00,$00
	.byte $A2,$22,$91,$3B
	.byte $A2,$22,$11,$11
	.byte $AA,$22,$1F,$11
	.byte $AA,$22,$04,$11
	.byte $BE,$EE,$84,$3B
	.byte $71,$C6,$74,$D0
	.byte $E7

;------------------------------------------------

L06A9:
            lda L0082              ; A5 82
            beq L06B0              ; F0 03
            jsr L13B1              ; 20 B1 13
L06B0:      rts                    ; 60

            ldy L0072              ; A4 72
            ldx L09F1,Y            ; BE F1 09
            lda L09F7,Y            ; B9 F7 09
            jsr L1551              ; 20 51 15
            jsr L1867              ; 20 67 18
            rts                    ; 60

            .byte $01,$00,$FF,$00,$00,$01,$00,$FF
            .byte $01,$FF,$01,$FF,$01,$01,$FF,$FF

            lda #$00               ; A9 00
            sta L0084              ; 85 84
            lda #$73               ; A9 73
            sta L0085              ; 85 85
            lda #$08               ; A9 08
            sta L0086              ; 85 86
            lda L0087              ; A5 87
            sta L0079              ; 85 79
            beq L0733              ; F0 51
            ldx L0079              ; A6 79
            cpx L0087              ; E4 87
            beq L06FF              ; F0 17
            ldy L0087              ; A4 87
            lda L0A00,Y            ; B9 00 0A
            cmp L0A00,X            ; DD 00 0A

L06F0:      .byte $00,$06,$07,$03,$04,$05,$02,$03
            .byte $07,$02,$07,$06,$03,$02,$06
L06FF:      .byte $06,$06,$02,$02,$04,$02,$06,$01
            .byte $04,$06,$03,$04,$03,$06,$07,$05
            .byte $01,$06,$01,$01,$01,$01,$06,$07
            .byte $06,$03,$01,$01,$01,$06,$06,$03
            .byte $04,$01,$01,$06,$04,$05,$06,$03
            .byte $07,$01,$01,$01,$06,$03,$03,$03
            .byte $07,$02,$05,$06
L0733:      .byte $07,$00,$06,$01,$04,$01,$01,$01
            .byte $01,$00,$85,$92,$A2
L0740:      .byte $00,$03,$03,$01,$03,$07,$07,$04
            .byte $02,$01,$03,$05,$04,$07,$03,$06
            .byte $07,$03,$03,$02,$03,$04,$07,$07
            .byte $02,$04,$03,$01,$03,$06,$03,$03
            .byte $03,$03,$06,$03,$07,$01,$02,$03
            .byte $01,$07,$07,$07,$03,$02,$04,$07
            .byte $03,$03,$07,$07,$02,$07,$02,$06
            .byte $02,$03,$06,$03,$04,$07,$06,$02
            .byte $01,$07,$03,$06,$04,$03,$06,$05
            .byte $07,$07,$07,$70,$04,$A9,$05,$85
L0790:      .byte $00,$0C,$0E
L0793:      .byte $10,$60,$40
L0796:      .byte $20,$FF,$FF,$FF,$02,$07,$02,$00
            .byte $00,$02,$00,$80,$00,$04,$04,$04
            .byte $00,$00,$00,$FE,$FC,$F8,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00
L07E0:      .byte $00
L07E1:      .byte $32
L07E2:      .byte $09
L07E3:      .byte $08,$01,$3C,$05,$08,$80,$0A,$14
            .byte $08,$0A,$1E,$05,$08,$13,$40,$05
            .byte $08,$00,$64,$85,$00,$00,$00,$8F
            .byte $00,$23,$00,$00,$00,$00,$00,$00
            .byte $00,$33,$35,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$80,$00,$00,$00,$64,$FF,$00
            .byte $06,$04,$FF,$01,$00,$02,$3A,$00
            .byte $00,$00,$07,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$64,$06,$90
            .byte $64,$06,$90,$64,$06,$90,$64,$06
            .byte $90,$64,$06,$00,$90

L0880:      .byte $12,$00,$00,$00
L0884:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$89,$DE,$01,$02,$04,$04,$04
            .byte $0A,$0A,$0A,$0A,$00,$00,$EC,$5A
            .byte $5A,$00,$00,$00,$02,$00,$00,$00
            .byte $0A,$28,$08,$19,$05,$FB,$F6,$7E
            .byte $6E,$00,$00,$00,$01,$00,$00,$00
            .byte $01,$04,$08,$04,$05,$FB,$9C,$64
            .byte $00,$00,$00,$00,$04,$0A,$14,$28
            .byte $01,$01,$09,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00
L0900:      .byte $02,$01,$01,$02,$02,$02,$02,$02
            .byte $02,$01,$02,$02,$02,$01,$02,$02
            .byte $02,$02,$01,$02,$02,$01,$01,$02
            .byte $01,$01,$03,$02,$02,$03,$02,$03
            .byte $02,$03,$03,$03,$03,$03,$01,$00
L0928:      .byte $03,$03,$03,$03,$02,$03,$03,$02
            .byte $02,$03,$02,$02,$02,$03,$02,$02
            .byte $02,$02,$03,$02,$02,$03,$03,$02
            .byte $03,$03,$01,$03,$03,$01,$02,$01
            .byte $02,$01,$02,$02,$02,$02,$03,$03
L0950:      .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A
L0972:      .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A
L0994:      .byte $5A,$5D,$5F,$60,$62,$64,$66,$68
            .byte $6A,$6C,$6D,$6E,$70,$71,$72,$73
            .byte $74,$75,$76,$77,$78,$79,$7A,$7B
            .byte $7C,$7D,$7E,$7F,$80,$80,$80,$80
            .byte $00,$00
L09B6:      .byte $00,$59,$57,$54,$52,$50,$4D,$4A
            .byte $48,$45,$42,$3F,$3C,$39,$36,$33
            .byte $30,$2D,$2A,$27,$24,$21,$1E,$1B
            .byte $18,$15,$12,$0F,$0C,$09,$06,$03
            .byte $00,$00,$00,$00,$02,$00,$04,$00
            .byte $06,$00,$08,$00,$0A,$00,$0C,$00
            .byte $0E,$00,$10,$00,$12,$00,$14,$00
            .byte $16,$00,$00
L09F1:      .byte $02,$03,$02,$03,$02,$00
L09F7:      .byte $38,$37,$1E
L09FA:      .byte $DF,$DD,$0B,$00,$00,$00
L0A00:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00
L0A09:      .byte $90
L0A0A:      .byte $00
L0A0B:      .byte $00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Moving sprite type
;
; $00 = Static
; $ff = Moving
;------------------------------------------------

L0A12:      .byte $00
            .byte $00,$00,$00,$00,$00,$00,$00
            .byte $00

;------------------------------------------------
; Current XPOS guards
;------------------------------------------------

L0A1B:      .byte $00				; Current XPOS Willy
L0A1C:      .byte $00,$00,$00,$00,$00,$00,$00
L0A23:      .byte $00

;------------------------------------------------
; Current YPOS guards
;------------------------------------------------

L0A24:      .byte $00				; Current YPOS Willy
L0A25:      .byte $00
L0A26:      .byte $00,$00,$00,$00,$00,$00
L0A2C:      .byte $00

;------------------------------------------------
; Direction of guards
;------------------------------------------------

L0A2D:      .byte $00				; Direction Willy
L0A2E:      .byte $00,$00,$00,$00,$00,$00,$00
            .byte $00

;------------------------------------------------
; Min.POS guards
;------------------------------------------------

L0A36:      .byte $00				; Min.POS Willy
            .byte $00,$00,$00,$08,$10,$00,$BD
            .byte $26

;------------------------------------------------
; Max.POS guards
;------------------------------------------------

L0A3F:      .byte $0C				; Max.POS Willy
            .byte $68,$68,$30,$30,$38,$A8,$8D
            .byte $81

L0A48:      .byte $0A
L0A49:      .byte $02,$02,$01,$02,$01,$03,$20,$F1
L0A51:      .byte $FF,$4E,$50,$95,$38,$05,$72,$C9
            .byte $25
L0A5A:      .byte $D0,$FF,$FF,$02,$FE,$02,$FE,$A5
            .byte $EC
L0A63:      .byte $02
L0A64:      .byte $FF
L0A65:      .byte $FF
L0A66:      .byte $FF,$FF,$FF,$FF,$7C,$0A
L0A6C:      .byte $C9,$00,$00,$01,$00,$00,$00,$7C
            .byte $0A,$68,$A8,$68,$AA,$68,$28,$60
L0A7C:      .byte $FF,$00
L0A7E:      .byte $40,$48
L0A80:      .byte $01
L0A81:      .byte $01,$01,$01,$01,$01,$01,$01,$01
            .byte $01,$01,$01
L0A8C:      .byte $D0,$C8,$40,$60,$70,$90,$B0,$C9
            .byte $A0,$D0,$06,$8D
L0A98:      .byte $66,$66,$49,$49,$49,$49,$49,$68
            .byte $AA,$68,$85,$FC
L0AA4:      .byte $10,$13
L0AA6:      .byte $0F,$11

L0AA8:      .byte $FE,$FD,$94,$96,$97,$99,$9B
            .byte $68,$84,$08,$08,$08

L0AB4:      .byte $44,$44,$6F,$6F,$6F,$6F,$6F
            .byte $08,$08,$08,$08,$08

L0AC0:      .byte $05
L0AC1:      .byte $20,$06,$60,$07,$A0,$08,$E0,$0A
            .byte $20,$0B,$60,$0C,$A0,$0D,$E0,$0F
            .byte $20,$10,$60,$11,$A0,$12,$E0,$14
            .byte $20,$15,$60,$16,$A0,$17,$E0,$19
            .byte $20,$1A,$60,$1B,$A0,$1C,$E0,$1E
            .byte $20,$1F,$60,$20,$A0,$21,$E0,$23
            .byte $20,$24,$60,$25,$A0,$26,$E0,$28
            .byte $20,$29,$60,$2A,$A0,$2B,$00

L0B00:      jmp L0C6B              ; 4C 6B 0C
L0B03:      jmp L0B2A              ; 4C 2A 0B
L0B06:      jmp L0CA3              ; 4C A3 0C
            jmp L0D50              ; 4C 50 0D
L0B0C:      jmp L0DFE              ; 4C FE 0D
L0B0F:      jmp L0E26              ; 4C 26 0E
            jmp L5400              ; 4C 00 54

L0B15:      jmp L0EC8              ; Plot Willy for each live

L0B18:      jmp L0F0C              ; Print roomname
L0B1B:      jsr L0FB6              ; 20 B6 0F
            jmp L0FF3              ; 4C F3 0F

L0B21:      jmp L1002              ; Game loop

            jmp L1026              ; 4C 26 10
L0B27:      jmp L107B              ; 4C 7B 10

L0B2A:      lda L006F              ; A5 6F
            beq L0B6C              ; F0 3E
            jsr L0BD8              ; 20 D8 0B
            lda #$80               ; A9 80
            sta L005D              ; 85 5D
            lda #$00               ; A9 00
            sta L007B              ; 85 7B
            sta L005E              ; 85 5E
            ldx L005F              ; A6 5F
            lda #$1F               ; A9 1F
            sta L007A              ; 85 7A
L0B41:      jsr L0B72              ; 20 72 0B
            dec L007A              ; C6 7A
            bne L0B41              ; D0 F9
            lda L005C              ; A5 5C
            asl A                  ; 0A
            clc                    ; 18
            adc L005F              ; 65 5F
            tay                    ; A8
            cmp #$D2               ; C9 D2
            bne L0B5B              ; D0 08
            lda L005B              ; A5 5B
            eor #$FF               ; 49 FF
            sta L005B              ; 85 5B
            lda #$08               ; A9 08
L0B5B:      cmp #$08               ; C9 08
            bne L0B67              ; D0 08
            lda L005C              ; A5 5C
            eor #$FF               ; 49 FF
            sta L005C              ; 85 5C
            inc L005C              ; E6 5C
L0B67:      sty L005F              ; 84 5F
            jsr L0BEE              ; 20 EE 0B
L0B6C:      jsr L0CEC              ; 20 EC 0C
            jmp L0D8C              ; 4C 8C 0D

L0B72:      stx L0096              ; 86 96
            txa                    ; 8A
            bpl L0B7F              ; 10 08
            ldx #$26               ; A2 26
            cmp #$F0               ; C9 F0
            bcs L0B7F              ; B0 02
            ldx #$27               ; A2 27
L0B7F:      lda L0900,X            ; BD 00 09
            cmp L005B              ; C5 5B
            bcc L0B88              ; 90 02
            eor #$FF               ; 49 FF
L0B88:      adc L005D              ; 65 5D
            sta L005D              ; 85 5D
            lda L005E              ; A5 5E
            clc                    ; 18
            adc L0928,X            ; 7D 28 09
            sta L005E              ; 85 5E
            ldy L007A              ; A4 7A
            sta L09B6,Y            ; 99 B6 09
            tax                    ; AA
            lda L005D              ; A5 5D
            sta L0994,Y            ; 99 94 09
            jsr L0BB2              ; 20 B2 0B
            lda L0090              ; A5 90
            ldx L007A              ; A6 7A
            sta L0950,X            ; 9D 50 09
            lda L0091              ; A5 91
            sta L0972,X            ; 9D 72 09
            ldx L0096              ; A6 96
            inx                    ; E8
            rts                    ; 60

L0BB2:      sta L0097              ; 85 97
            jsr L5400              ; 20 00 54
            lda L0097              ; A5 97
            and #$07               ; 29 07
            tax                    ; AA
            lda L0BD0,X            ; BD D0 0B
            sta L0097              ; 85 97

            ldy #$00               ; A0 00
            lda (L0090),Y          ; B1 90
            beq L0BCB              ; F0 04
            lda L007A              ; A5 7A
            sta L007B              ; 85 7B
L0BCB:      lda L0097              ; A5 97
            sta (L0090),Y          ; 91 90
            rts                    ; 60

L0BD0:      .byte $80,$40,$20,$10,$08,$04,$02,$01

;--------------------------------------------

L0BD8:      ldx #$1F               ; A2 1F
            ldy #$00               ; A0 00
L0BDC:      lda L0950,X            ; BD 50 09
            sta L0090              ; 85 90
            lda L0972,X            ; BD 72 09
            sta L0091              ; 85 91
            lda #$00               ; A9 00
            sta (L0090),Y          ; 91 90
            dex                    ; CA
            bpl L0BDC              ; 10 EF
            rts                    ; 60

;--------------------------------------------

L0BEE:      ldx L009F              ; A6 9F
            bne L0C09              ; D0 17
            lda L007B              ; A5 7B
            beq L0C6A              ; F0 74
            ldx #$00               ; A2 00
            stx L009A              ; 86 9A
            lda L0A24              ; AD 24 0A
L0BFD:      inx                    ; E8
            cmp L09B6,X            ; DD B6 09
            bcc L0BFD              ; 90 FA
            cpx #$02               ; E0 02
            bcc L0C5D              ; 90 56
            stx L009F              ; 86 9F
L0C09:      cpx #$0F               ; E0 0F
            bcc L0C11              ; 90 04
            lda #$00               ; A9 00
            sta L008B              ; 85 8B
L0C11:      lda L0065              ; A5 65
            cmp #$0E               ; C9 0E
            bcs L0C5D              ; B0 46
            lda #$00               ; A9 00
            sta L0064              ; 85 64
            sta L0065              ; 85 65
            lda L0994,X            ; BD 94 09
            sec                    ; 38
            sbc #$04               ; E9 04
            and #$FE               ; 29 FE
            sta L0A1B              ; 8D 1B 0A
            lda L09B6,X            ; BD B6 09
            sec                    ; 38
            sbc #$06               ; E9 06
            bpl L0C32              ; 10 02
            lda #$C0               ; A9 C0
L0C32:      sta L0A24              ; 8D 24 0A
            lda L008E              ; A5 8E
            beq L0C6A              ; F0 31
            lda L005B              ; A5 5B
            eor L005C              ; 45 5C
            dex                    ; CA
            eor L008E              ; 45 8E
            bmi L0C4F              ; 30 0D
            inx                    ; E8
            lda L0AA6              ; AD A6 0A
            cmp L0055              ; C5 55
            bne L0C4E              ; D0 04
            cpx #$14               ; E0 14
            bcs L0C4F              ; B0 01
L0C4E:      inx                    ; E8
L0C4F:      stx L009F              ; 86 9F
            cpx #$03               ; E0 03
            bcs L0C6A              ; B0 15
            lda L0A24              ; AD 24 0A
            adc #$04               ; 69 04
            sta L0A24              ; 8D 24 0A
L0C5D:      lda L0A24              ; AD 24 0A
            and #$FC               ; 29 FC
            sta L0A24              ; 8D 24 0A
            lda #$00               ; A9 00
            sta L009F              ; 85 9F
            rts                    ; 60
L0C6A:      rts                    ; 60

;--------------------------------------------
; Print 'Items collected 000 Time  7:00pm'
; at bottomline
;--------------------------------------------

L0C6B:
	lda #$00		; Set cursor 0,23
	sta XPOS
	lda #23
	sta YPOS

            ldx #$FF               ; A2 FF
L0C6D:      inx                    ; E8
            lda L0C7E,X            ; BD 7E 0C
            jsr OSWRCH              ; 20 EE FF
            cpx #31               ; C9 04
            bne L0C6D              ; D0 F5

            jsr L0CC4              ; Print nr of items collected

            jmp L0D2C              ; Goto print time

L0C7E:      .byte "Items collected 000 "
            .byte "Time  7:00pm"

;--------------------------------------------
; Print nr of items collected
;--------------------------------------------

L0CA3:      lda #$18               ; A9 18
            jsr L107B              ; 20 7B 10
            dec L0044              ; C6 44
            bne L0CAE              ; D0 02
            inc L009E              ; E6 9E
L0CAE:      inc L0041              ; E6 41
            lda L0041              ; A5 41
            cmp #$0A               ; C9 0A
            bcc L0CC4              ; 90 0E
            inc L0042              ; E6 42
            ldx #$00               ; A2 00
            stx L0041              ; 86 41
            cmp L0042              ; C5 42
            bne L0CC4              ; D0 04
            inc L0043              ; E6 43
            stx L0042              ; 86 42

; Print nr of items collected

L0CC4:      ldx #$10               ; A2 10

            ldy L0043              ; A4 43
            jsr L0CD6              ; 20 D6 0C

            lda L0042              ; A5 42
            jsr L0CE5              ; 20 E5 0C

            lda L0041              ; A5 41
            jsr L0CE5              ; 20 E5 0C

            rts                    ; 60

;--------------------------------------------
; Print number in Y as digit at X,22
;--------------------------------------------

L0CD6:
	stx XPOS		; Set XPOS
	lda #23
	sta YPOS		; Set YPOS

; Convert digit to ASCII character and print it

;            lda #$1F               ; A9 1F
;            jsr OSWRCH              ; 20 EE FF
;            txa                    ; 8A
;            jsr OSWRCH              ; 20 EE FF
;            lda #$14               ; A9 14
;            jsr OSWRCH              ; 20 EE FF

            tya                    ; 98
L0CE5:      clc                    ; 18
            adc #$30               ; 69 30
            jsr OSWRCH              ; 20 EE FF
            rts                    ; 60

;--------------------------------------------
; Increment and print time
;--------------------------------------------

; Check timer if clock has to be updated

L0CEC:      dec L0057              ; C6 57
            bne L0D4B              ; D0 5B

	ldy #$00		; Reset clock counter

            inc L0D4C              ; EE 4C 0D
            lda L0D4C              ; AD 4C 0D
            cmp #$0A               ; C9 0A
            bcc L0D2C              ; 90 32
            sty L0D4C              ; 8C 4C 0D

            inc L0D4D              ; EE 4D 0D
            lda L0D4D              ; AD 4D 0D
            cmp #$06               ; C9 06
            bcc L0D2C              ; 90 25
            sty L0D4D              ; 8C 4D 0D

            inc L0D4E              ; EE 4E 0D
            lda L0D4E              ; AD 4E 0D
            cmp #$0A               ; C9 0A
            bcc L0D1C              ; 90 08
            sty L0D4E              ; 8C 4E 0D

            lda #$01               ; A9 01
            sta L0D4F              ; 8D 4F 0D

L0D1C:      lda L0D4E              ; AD 4E 0D
            cmp #$02               ; C9 02
            bne L0D2C              ; D0 09

            lda L0D4F              ; AD 4F 0D
            bmi L0D2C              ; 30 04

            inc L009D              ; E6 9D

.if cheat<>1 
            inc L0063              ; E6 63
.endif

; Print time on bottomline

L0D2C:      ldx #$19               ; A2 19
            ldy L0D4F              ; AC 4F 0D
            jsr L0CD6              ; 20 D6 0C

            lda L0D4E              ; AD 4E 0D
            jsr L0CE5              ; 20 E5 0C

            lda #$3A               ; A9 3A
            jsr OSWRCH              ; 20 EE FF

            lda L0D4D              ; AD 4D 0D
            jsr L0CE5              ; 20 E5 0C

            lda L0D4C              ; AD 4C 0D
            jsr L0CE5              ; 20 E5 0C
L0D4B:      rts                    ; 60

L0D4C:      .byte $00
L0D4D:      .byte $00
L0D4E:      .byte $07
L0D4F:      .byte $F0

;--------------------------------------------
; Set vars
;--------------------------------------------

L0D50:      lda #$00               ; A9 00

            sta L009A              ; 85 9A
            sta L0041              ; 85 41
            sta L0042              ; 85 42
            sta L0043              ; 85 43
            sta L0D4C              ; 8D 4C 0D
            sta L0D4D              ; 8D 4D 0D
            sta L009E              ; 85 9E
            sta L009D              ; 85 9D
            sta L0064              ; 85 64
            sta L0065              ; 85 65

            lda #$F0               ; A9 F0
            sta L0D4F              ; 8D 4F 0D

            lda #$07               ; A9 07
            sta L0D4E              ; 8D 4E 0D

            lda #$07               ; A9 07
            sta L009B              ; 85 9B

            lda #$68               ; A9 68
            sta L0A24              ; 8D 24 0A

            lda #$A8               ; A9 A8
            sta L0A1B              ; 8D 1B 0A

            lda #$12               ; A9 12
            sta L0055              ; 85 55

            lda #$64               ; A9 64
            sta L0044              ; 85 44

            jsr L1100              ; 20 00 11

	bit L0381		; Check for Joystick AtoMMC
	bpl no_joy
	jsr joyinit

no_joy:
            rts                    ; 60

;--------------------------------------------
; Check master bedroom
;--------------------------------------------

L0D8C:      lda L0055              ; A5 55
            cmp #$1E               ; C9 1E
            bne L0DB0              ; D0 1E

            lda L0A24              ; Y-Pos Willy
            cmp #$67               ; C9 67
            bcs L0DA2              ; B0 09

            ldx #$81               ; A2 81
            cmp #$60               ; C9 60
            bcs L0DAD              ; B0 0E
            inx                    ; E8
            bne L0DAD              ; D0 0B

L0DA2:      ldx #$7F               ; A2 7F

            lda L0A0A              ; AD 0A 0A
            cmp #$7F               ; C9 7F
            bne L0DAD              ; D0 02

            ldx #$80               ; A2 80

L0DAD:      stx L0A0A              ; 8E 0A 0A

L0DB0:      lda L009E              ; A5 9E
            beq L0DFD              ; F0 49
            bmi L0DCD              ; 30 17

            lda L0055              ; A5 55
            cmp #$1E               ; C9 1E
            bne L0DFD              ; D0 41

            lda #$00               ; A9 00
            sta L0A49              ; Sprite type

            lda L0A1B              ; X-pos Willy
            cmp #$18               ; C9 18
            bne L0DFD              ; D0 35

            lda #$FF               ; Set end of game mode
            sta L009E              ; 85 9E
            rts                    ; 60

L0DCD:      lda #$02               ; A9 02
            sta L008E              ; 85 8E

            lda #$00               ; A9 00
            sta L008B              ; 85 8B

; Check jump in Dumb waiter room

            lda L0055              ; A5 55
            cmp #$3F               ; C9 3F
            bne L0DE6              ; D0 0B

            ldx L0A1B              ; X-pos Willy
            cpx #$72               ; E0 72
            bne L0DE6              ; D0 04

            lda #$FF               ; A9 FF
            sta L008B              ; Jump key flag

; Check toilet position The bathroom

L0DE6:      cmp #$12               ; C9 12
            bne L0DFD              ; D0 13

            lda L0A1B              ; AD 1B 0A
            cmp #$D8               ; C9 D8
            bcc L0DFD              ; 90 0C

;            lda #$0A               ; A9 0A
;            ora L0A0B              ; 0D 0B 0A
            lda #$85              ; 0D 0B 0A
            sta L0A0B              ; 8D 0B 0A

            lda #$02               ; A9 02
            sta L009C              ; 85 9C

L0DFD:      rts                    ; 60

L0DFE:      ldy #$20               ; A0 20
            jsr L0E11              ; 20 11 0E
            ldy #$40               ; A0 40
            jsr L0E11              ; 20 11 0E
            lda L0A24              ; AD 24 0A
            and #$07               ; 29 07
            beq L0E25              ; F0 16
            ldy #$60               ; A0 60
L0E11:      jsr L0E15              ; 20 15 0E
            iny                    ; C8
L0E15:      lda (L0060),Y          ; B1 60
            bpl L0E25              ; 10 0C
            cmp #$8A               ; C9 8A
            bcs L0E25              ; B0 08
            and #$0F               ; 29 0F
            tax                    ; AA
            lda #$02               ; A9 02
            sta L0A63,X            ; 9D 63 0A
L0E25:      rts                    ; 60

L0E26:      ldy #$01               ; A0 01
L0E28:      ldx L0A7C,Y            ; BE 7C 0A
            bmi L0E57              ; 30 2A
            beq L0E53              ; F0 24
            lda L0057              ; A5 57
            and #$01               ; 29 01
            bne L0E53              ; D0 1E
            dex                    ; CA
            bne L0E46              ; D0 0E
            lda #$FF               ; A9 FF
            sta L0A7C,Y            ; 99 7C 0A
            lda L0EC0,Y            ; B9 C0 0E
            sta L0EC4,Y            ; 99 C4 0E
            jmp L0E70              ; 4C 70 0E

L0E46:      txa                    ; 8A
            sta L0A7C,Y            ; 99 7C 0A
            cmp #$03               ; C9 03
            bne L0E53              ; D0 05
            lda #$20               ; A9 20
            jsr L107B              ; 20 7B 10
L0E53:      dey                    ; 88
            bpl L0E28              ; 10 D2
            rts                    ; 60

L0E57:      jsr L0E84              ; 20 84 0E
            lda L0EC4,Y            ; B9 C4 0E
            clc                    ; 18
            adc L0EC2,Y            ; 79 C2 0E
            sta L0EC4,Y            ; 99 C4 0E
            cmp L0EC0,Y            ; D9 C0 0E
            bne L0E70              ; D0 07
            lda #$7F               ; A9 7F
            sta L0A7C,Y            ; 99 7C 0A
            bpl L0E53              ; 10 E3
L0E70:      jsr L0E84              ; 20 84 0E
            ldx #$08               ; A2 08
            jsr L1115              ; 20 15 11
            ldy #$20               ; A0 20
            lda (L0060),Y          ; B1 60
            ldy L0096              ; A4 96
            sta L0EC6,Y            ; 99 C6 0E
            jmp L0E53              ; 4C 53 0E

;--------------------------------------------
; Plot/wipe arrow
;--------------------------------------------

L0E84:      sty L0096              ; 84 96
	stx x_tmp

            lda L0EC4,Y            ; B9 C4 0E
            sta L0A23              ; 8D 23 0A

            ldx L0A7E,Y            ; BE 7E 0A
            stx L0A2C              ; 8E 2C 0A

            jsr L5400              ; 20 00 54

            lda L0EBE,Y            ; B9 BE 0E
            sta L0EA2+1              ; 8D A3 0E
	lda L0EBF,Y
	sta L0EA2+2

            lda L0EC6,Y            ; B9 C6 0E
            bmi L0EAF              ; 30 0F

; Plot arrow

            ldx #$07               ; A0 07
L0EA2:      lda L4660,x            ; B9 60 46
	ldy scrtab,x
            eor (L0090),Y          ; 51 90
            sta (L0090),Y          ; 91 90
            dex                    ; 88
            bne L0EA2              ; D0 F6
	ldx x_tmp
            ldy L0096              ; A4 96
            rts                    ; 60

; Wipe arrow

L0EAF:      lda #$00               ; A9 00
            sta L0EC6,Y            ; 99 C6 0E

            ldx #$07               ; A0 07
L0EB6:
	ldy scrtab,x
            sta (L0090),Y          ; 91 90
            dex                    ; 88
            bne L0EB6              ; D0 FB
	ldx x_tmp
            ldy L0096              ; A4 96
            rts                    ; 60

L0EBE:      .byte <L4670,<L4660
L0EBF:	.byte >L4670,>L4660

L0EC0:      .byte $00,$F8
L0EC2:      .byte $08,$F8
L0EC4:      .byte $00,$00
L0EC6:      .byte $00,$00

;--------------------------------------------
; Plot Willy for each live
;--------------------------------------------

L0EC8:      lda L0055              ; A5 55
            cmp #$3B               ; C9 3B
            bne L0ED3              ; D0 05

;            lda #$00               ; A9 00
;            sta L6082              ; 8D 82 60

L0ED3:      lda L0057              ; A5 57
            and #$03               ; 29 03
            bne L0F06              ; D0 2D

;            lda L0F07              ; AD 07 0F
;            clc                    ; 18
;            adc #$20               ; 69 20
;            sta L0F07              ; 8D 07 0F
;            sta L0092              ; 85 92
;            lda #$48               ; A9 48
;            sta L0093              ; 85 93

	lda L0F07
	clc
	adc #$02
	sta L0F07

	lsr a
	and #$07
	tax

	lda sprdata_lb,x
	sta L0092
	lda sprdata_hb,x
	sta L0093

            lda #$F0               ; A9 F0
            sta L0097              ; 85 97

            lda L009B              ; A5 9B
            beq L0F06              ; F0 16
            sta L0096              ; 85 96
            lda #$FF               ; A9 FF
            sta L0089              ; 85 89

L0EF6:      lda L0097              ; XPOS
            clc                    ; 18
            adc #$10               ; 69 10
            sta L0097              ; 85 97

            ldx L004D              ; YPOS
            jsr L5422              ; Plot sprite

            dec L0096              ; C6 96
            bne L0EF6              ; D0 F0

L0F06:      rts                    ; 60

sprdata_lb:
	.byte <L4800,<L4820,<L4840,<L4860,<L4880,<L48A0,<L48C0,<L48E0
sprdata_hb:
	.byte >L4800,>L4820,>L4840,>L4860,>L4880,>L48A0,>L48C0,>L48E0

L0F07:      .byte $00,$00,$0F,$F0,$FF

;--------------------------------------------
; Print roomname
;--------------------------------------------

L0F0C:      ldy #$04               ; A0 04

L0F0E:      ldx #$02               ; A2 02
            jsr L1112              ; 20 12 11

            sta L09F1,Y            ; 99 F1 09
            dey                    ; 88
            bpl L0F0E              ; 10 F5

            ldy #$05               ; A0 05
L0F1B:      ldx #$08               ; A2 08
            jsr L1112              ; 20 12 11
            sta L09F7,Y            ; 99 F7 09
            dey                    ; 88
            bpl L0F1B              ; 10 F5
            ldx #$06               ; A2 06
            jsr L1112              ; 20 12 11
            ldx #$03               ; A2 03
            jsr L1112              ; 20 12 11
            ldx #$03               ; A2 03
            jsr L1112              ; 20 12 11
            tax                    ; AA
            lda L10A1,X            ; BD A1 10
            sta L0003              ; 85 03
            ldy L0055              ; A4 55
            lda L06F0,Y            ; B9 F0 06
            ldy #$00               ; A0 00
            jsr L108F              ; 20 8F 10
            ldy L0055              ; A4 55
            lda L0740,Y            ; B9 40 07
            ldy #$01               ; A0 01
            jsr L108F              ; 20 8F 10
            lda #$01               ; A9 01
            sta L0097              ; 85 97

;            lda #$1F               ; A9 1F
;            jsr OSWRCH              ; 20 EE FF
            ldx #$04               ; A2 04
            jsr L1112              ; 20 12 11
	sta XPOS

;            jsr OSWRCH              ; 20 EE FF
;            lda #$10               ; A9 10
;            jsr OSWRCH              ; 20 EE FF
	lda #$11
	sta YPOS

L0F65:      ldx #$05               ; A2 05
            jsr L1112              ; 20 12 11
            cmp #$1B               ; C9 1B
            bcs L0F74              ; B0 06
            jsr L0FA5              ; 20 A5 0F
            jmp L0F65              ; 4C 65 0F

L0F74:      bne L0F7E              ; D0 08

            lda #$27               ; A9 27
            jsr OSWRCH              ; 20 EE FF

            jmp L0F65              ; 4C 65 0F

L0F7E:      cmp #$1D               ; C9 1D
            beq L0F8B              ; F0 09
            bcs L0F85              ; B0 01
            rts                    ; 60

L0F85:      cmp #$1E               ; C9 1E
            bne L0F93              ; D0 0A
            inc L0097              ; E6 97

L0F8B:      lda #$20               ; A9 20
            jsr OSWRCH              ; 20 EE FF

            jmp L0F65              ; 4C 65 0F

L0F93:      lda #$13               ; A9 13
            jsr L0FA5              ; 20 A5 0F

            lda #$68               ; A9 68
            jsr OSWRCH              ; 20 EE FF

            lda #$65               ; A9 65
            jsr OSWRCH              ; 20 EE FF
            jmp L0F65              ; 4C 65 0F

L0FA5:      clc                    ; 18
            adc #$61               ; 69 61
            ldy L0097              ; A4 97
            beq L0FB2              ; F0 06
            and #$DF               ; 29 DF
            ldx #$00               ; A2 00
            stx L0097              ; 86 97

L0FB2:      jsr OSWRCH              ; 20 EE FF
            rts                    ; 60

;---------------------------------------------

L0FB6:      ldy #$01               ; A0 01

L0FB8:      lda #$00               ; A9 00
            sta L0EC6,Y            ; 99 C6 0E
            sta L0A7C,Y            ; 99 7C 0A

            ldx #$01               ; A2 01
            jsr L1112              ; 20 12 11
            tax                    ; AA
            beq L0FEA              ; F0 22

            ldx #$04               ; A2 04
            jsr L1112              ; 20 12 11
            tax                    ; AA
            beq L0FEA              ; F0 1A

            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            eor #$78               ; 49 78
            sta L0A7E,Y            ; 99 7E 0A

            ldx #$03               ; A2 03
            jsr L1112              ; 20 12 11
            tax                    ; AA

            lda L0FEE,X            ; BD EE 0F
            sta L0A7C,Y            ; 99 7C 0A
            sta L0EC4,Y            ; 99 C4 0E
            sta L0EC6,Y            ; 99 C6 0E

L0FEA:      dey                    ; 88
            bpl L0FB8              ; 10 CB
            rts                    ; 60

L0FEE:      .byte $D0,$16,$1E,$26,$7F

L0FF3:      lda #$80               ; A9 80
            sta L004E              ; 85 4E

            lda #$00               ; A9 00
            ldx #$3F               ; A2 3F
L0FFB:      sta L4600,X            ; 9D 00 46
            dex                    ; CA
            bpl L0FFB              ; 10 FA
            rts                    ; 60

;--------------------------------------------
; Game loop
;--------------------------------------------

L1002:      jsr L0440              ; Display intro screen
            jsr L0D50              ; Set vars

L1008:      jsr L110C              ; Build playfield

;	lda L0A1B			; XPOS Willy
;	sta hitflag

L100B:
            jsr L0EC8              ; Plot Willy for each live
            jsr L1106              ; Plot sprites
            jsr L1055              ; 20 55 10

	jsr L1073

            lda L0063              ; A5 63
	beq L100B

;            bne L100D              ; F0 E9
;	lda #0
;	sta hitflag
;	jmp L100B
;L100D:
;	lda hitflag
;	beq L100C
;	cmp L0A1B
;	beq L100B
L100C:
            lda L009B              ; A5 9B
            bpl L1008              ; 10 E2

; Game over, no lives left

L1026:      ldx #$00               ; A2 00
	jsr vdu16

            jsr L1103              ; 20 03 11

            ldx #$70               ; A2 00
            stx L1070              ; 8E 70 10

L103B:
	jsr L1073		; Wait

; Print 'Game over'

	lda #11			; Set cursor 11,8
	sta XPOS
	lda #8
	sta YPOS

            ldy #$00               ; A0 00

L1042:
	lda L1070
	and #1
	beq L1043
	lda L1072,y
	jmp L1044
L1043:
            lda L1071,Y            ; B9 6C 10
L1044:
            jsr OSWRCH              ; 20 EE FF
            iny                    ; C8
            cpy #$0A               ; C0 0F
            bne L1042              ; D0 F5

            inc L1070              ; EE 70 10
            bpl L103B              ; 10 E9

            jmp L1002              ; 4C 02 10

L1055:      ldx #$03               ; Scan ESC-key
            jsr L54C0              ; 20 C0 54
            beq L1061              ; F0 05
            pla                    ; 68
            pla                    ; 68
            jmp L1002              ; 4C 02 10

L1061:      rts                    ; 60

L1062:      .byte $18,$00,$00,$80,$01,$7F,$04,$FF,$03
            .byte $10

L106C:      .byte $1F,$0B,$08,$11
L1070:      .byte $00

;                  G   a   m   e   _   _   O
L1071:      .byte $47,$61,$6D,$65,$09,$09,$4F
;                  v   e   r
            .byte $76,$65,$72
L1072:	.byte $20,$20,$20,$20,$09,$09,$20,$20,$20,$20

;------------------------------------------------

L1073:
	jsr $fe6b
;	jsr $fe6b
	jsr $fe66
	rts

L107B:
	stx L108D
	sty L108E
;	lsr a
;	tay
	jsr L5703
	ldx L108D
	ldy L108E
	rts

L108D:	.byte 0
L108E:	.byte 0

;------------------------------------------------

L108F:      .byte $AA,$BD,$99,$10,$05,$03,$99,$00
            .byte $00,$60,$26,$22,$24,$20,$06,$02
            .byte $04,$00
L10A1:      .byte $19,$10,$09,$08,$11,$10,$01,$00
            .byte $A5,$04,$C9,$04,$90,$FA,$60,$07
            .byte $F0,$01,$05,$BA,$02,$8C,$01,$05
            .byte $AC,$02,$8A,$01,$05,$9E,$02,$89
            .byte $01,$05,$83,$02,$88,$01,$A9,$12
            .byte $20,$EE,$FF

            lda #$00               ; A9 00
            jsr OSWRCH              ; 20 EE FF

            lda L0DFE+1              ; AD FF 0D
            eor #$03               ; 49 03
            sta L0DFE+1              ; 8D FF 0D
            jsr OSWRCH              ; 20 EE FF

            ldx #$00               ; A2 00
            lda #$00               ; A9 00
            sta L006E              ; 85 6E

            lda #$2F               ; A9 2F
            sta L006F              ; 85 6F

            lda #$19               ; A9 19
            jsr OSWRCH              ; 20 EE FF

            ldy #$00               ; A0 00
L10ED:      lda (L006E),Y          ; B1 6E
            jsr OSWRCH              ; 20 EE FF
            iny                    ; C8
            cpy #$05               ; C0 05
            bne L10ED              ; D0 F6

            clc                    ; 18
            lda L006E              ; A5 6E
            adc #$05               ; 69 05
            sta L006E              ; 85 6E
            lda L006F              ; A5 6F

L1100:      jmp L1B8A              ; 4C 8A 1B
L1103:      jmp L1CA2              ; 4C A2 1C

L1106:      jmp L150C              ; 4C 0C 15

            jmp L164D              ; 4C 4D 16

L110C:      jmp L111B              ; Build playfield

L110F:      jmp L139C              ; 
L1112:      jmp L11A3              ; 4C A3 11
L1115:      jmp L1721              ; 4C 21 17

L1118:      jmp L1B2E              ; 4C 2E 1B

; Build playfield

L111B:      jsr L112B              ; Display screen
            jsr L164D              ; 20 4D 16
            jsr L0B1B              ; 20 1B 0B
            jmp L1BDB              ; 4C DB 1B

L1127:      .byte $00
L1128:      .byte $00
L1129:      .byte $00
L112A:      .byte $00

;--------------------------------------------
; Display screen
;--------------------------------------------

L112B:      lda #$00               ; A9 00
            sta L0052              ; 85 52
            sta L0053              ; 85 53
            sta L009F              ; 85 9F
            sta L0057              ; 85 57

            ldx L0055              ; A6 55
            jsr L1B95              ; 20 95 1B

;            lda #$0C               ; A9 0C
;            jsr OSWRCH              ; 20 EE FF
	jsr vdu12

            jsr L1B3B              ; 20 3B 1B
            jsr L0B18              ; Print roomname

            lda #$FF               ; A9 FF
            sta L0066              ; 85 66
            sta L005B              ; 85 5B
            sta L005C              ; 85 5C

            lda #$D8               ; A9 D8
            sta L005F              ; 85 5F

            lda #$01               ; A9 01
            sta L009C              ; 85 9C
            sta L0067              ; 85 67

            lda L009D              ; A5 9D
            sta L0063              ; 85 63

            lda L0A24              ; AD 24 0A
            sta L0062              ; 85 62

            lda #$01               ; A9 01
            sta L0072              ; 85 72

            lda #$00               ; A9 00
            sta L0073              ; 85 73
            sta L0070              ; 85 70
            sta L0071              ; 85 71

            jsr L0B00              ; Print 'Items collected 000 Time  7:00pm'
            jsr L1713              ; Reset shadowscreen

L1172:      ldy #$FF               ; A0 FF
L1174:      iny                    ; C8
            ldx #$02               ; A2 02
            jsr L11A3              ; 20 A3 11
            cmp #$03               ; C9 03
            beq L1174              ; F0 F6

            sta L007B              ; 85 7B
L1180:      sty L0096              ; 84 96
            tya                    ; 98
            asl A                  ; 0A
            asl A                  ; 0A
            adc L007B              ; 65 7B
            sec                    ; 38
            sbc L0096              ; E5 96
            cmp #$06               ; C9 06
            beq L11A2              ; F0 14
            asl A                  ; 0A
            tax                    ; AA
            lda L11C5,X            ; BD C5 11
            sta L119C+1             ; 8D 9D 11
            lda L11C6,X            ; BD C6 11
            sta L119C+2              ; 8D 9E 11
L119C:
            jsr L1111              ; 20 11 11
            jmp L1172              ; 4C 72 11

L11A2:      rts                    ; 60

;--------------------------------------------

L11A3:      sty L007B              ; 84 7B
            lda #$00               ; A9 00
            sta L0096              ; 85 96
L11A9:      dec L0053              ; C6 53
            bpl L11B9              ; 10 0C

            lda #$07               ; A9 07
            sta L0053              ; 85 53

            ldy L0052              ; A4 52
            lda (L0050),Y          ; Level data pointer
            sta L0054              ; 85 54
            inc L0052              ; E6 52
L11B9:      lsr L0054              ; 46 54
            rol L0096              ; 26 96
            dex                    ; CA
            bne L11A9              ; D0 E9
            lda L0096              ; A5 96
            ldy L007B              ; A4 7B
            rts                    ; 60

;--------------------------------------------

L11C5:      .byte <L11D7
L11C6:      .byte >L11D7,<L11DF,>L11DF,<L11EE,>L11EE,<L1238,>L1238
            .byte <L1215,>L1215,<L11F8,>L11F8,<L11A2,>L11A2,<L11A2
            .byte >L11A2,<L128E,>L128E
L11D7:
            ldx #$03
            jsr L11A3              ; 20 A3 11
            sta L0072              ; 85 72
            rts                    ; 60
L11DF:
            ldx #$05               ; A2 05
            jsr L11A3              ; 20 A3 11
            sta L0070              ; 85 70
            ldx #$04               ; A2 04
            jsr L11A3              ; 20 A3 11
            sta L0071              ; 85 71
            rts                    ; 60
L11EE:
            lda #$01               ; A9 01
            ldx #$00               ; A2 00
            ldy #$05               ; A0 05
            jsr L1335              ; 20 35 13
            rts                    ; 60
L11F8:
            lda L0072              ; A5 72
            sta L0081              ; 85 81
            lda #$02               ; A9 02
            sta L0072              ; 85 72
            lda #$01               ; A9 01
            ldx #$08               ; A2 08
            ldy #$04               ; A0 04
            jsr L1335              ; 20 35 13
            lda L0081              ; A5 81
            sta L0072              ; 85 72
            lda L0070              ; A5 70
            clc                    ; 18
            adc L0077              ; 65 77
            sta L0070              ; 85 70
            rts                    ; 60
L1215:
            ldx #$04               ; A2 04
            jsr L11A3              ; 20 A3 11
            sta L006E              ; 85 6E
L121C:      ldx #$05               ; A2 05
            jsr L11A3              ; 20 A3 11
            sta L0070              ; 85 70
            ldx #$04               ; A2 04
            jsr L11A3              ; 20 A3 11
            sta L0071              ; 85 71
            jsr L139C              ; 20 9C 13
            dec L006E              ; C6 6E
            bpl L121C              ; 10 EB
            lda #$00               ; A9 00
            sta L0070              ; 85 70
            sta L0071              ; 85 71
            rts                    ; 60
L1238:
            ldx #$05               ; A2 05
            jsr L11A3              ; 20 A3 11
            sta L0079              ; 85 79
            lda L0070              ; A5 70
            sta L0075              ; 85 75
            lda L0071              ; A5 71
            sta L0076              ; 85 76
            ldx #$04               ; A2 04
            jsr L11A3              ; 20 A3 11
            sta L0071              ; 85 71
            lda L0076              ; A5 76
            sec                    ; 38
            sbc L0071              ; E5 71
            ldx #$01               ; A2 01
            bcs L125D              ; B0 06
            eor #$FF               ; 49 FF
            adc #$01               ; 69 01
            ldx #$FF               ; A2 FF
L125D:      sta L0076              ; 85 76
            stx L007A              ; 86 7A
L1261:      lda #$00               ; A9 00
            sta L007C              ; 85 7C
            lda L0079              ; A5 79
            sta L0074              ; 85 74
            lda L0075              ; A5 75
            sta L0070              ; 85 70
            lda #$01               ; A9 01
            ldx #$80               ; A2 80
            jsr L1335              ; 20 35 13
            lda L0071              ; A5 71
            clc                    ; 18
            adc L007A              ; 65 7A
            sta L0071              ; 85 71
            dec L0076              ; C6 76
            bpl L1261              ; 10 E2
            lda L0071              ; A5 71
            sec                    ; 38
            sbc L007A              ; E5 7A
            sta L0071              ; 85 71
            lda L0070              ; A5 70
            clc                    ; 18
            adc L0077              ; 65 77
            sta L0070              ; 85 70
            rts                    ; 60
L128E:
            lda L0070              ; A5 70
            sta L0075              ; 85 75
            lda L0071              ; A5 71
            sta L0076              ; 85 76
            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11
            ldx #$01               ; A2 01
            stx L006D              ; 86 6D
            sta L007D              ; 85 7D
            tay                    ; A8
            beq L12A6              ; F0 02
            ldx #$FF               ; A2 FF
L12A6:      stx L007E              ; 86 7E
            ldx #$04               ; A2 04
            jsr L11A3              ; 20 A3 11
            sta L007A              ; 85 7A
            sta L007F              ; 85 7F
            sec                    ; 38
            sbc L0071              ; E5 71
            sta L0080              ; 85 80
            bcs L12CB              ; B0 13
            eor #$FF               ; 49 FF
            adc #$01               ; 69 01
            sta L0080              ; 85 80
            dec L006D              ; C6 6D
            lda L007A              ; A5 7A
            ldx L0071              ; A6 71
            sta L0071              ; 85 71
            stx L007A              ; 86 7A
            jmp L12E2              ; 4C E2 12

L12CB:      ldx L0080              ; A6 80
            lda L007E              ; A5 7E
            eor #$FF               ; 49 FF
            adc #$00               ; 69 00
            sta L007E              ; 85 7E
            bmi L12DC              ; 30 05
            txa                    ; 8A
            eor #$FF               ; 49 FF
            tax                    ; AA
            inx                    ; E8
L12DC:      txa                    ; 8A
            clc                    ; 18
            adc L0070              ; 65 70
            sta L0070              ; 85 70
L12E2:      lda #$01               ; A9 01
            sta L007C              ; 85 7C
            lda L007A              ; A5 7A
            sta L0074              ; 85 74
            lda L0071              ; A5 71
            sta L0081              ; 85 81
            lda #$01               ; A9 01
            ldx #$80               ; A2 80
            jsr L1335              ; 20 35 13
            lda L0081              ; A5 81
            sta L0071              ; 85 71
            lda L0070              ; A5 70
            clc                    ; 18
            adc L007E              ; 65 7E
            sta L0070              ; 85 70
            dec L007A              ; C6 7A
            dec L0080              ; C6 80
            bpl L12E2              ; 10 DC
            lda L0075              ; A5 75
            sta L0070              ; 85 70
            lda L0076              ; A5 76
            sta L0071              ; 85 71
            lda L007D              ; A5 7D
            sta L007C              ; 85 7C
            lda L007F              ; A5 7F
            sta L0074              ; 85 74
            lda L0072              ; A5 72
            sta L0081              ; 85 81
            lda #$02               ; A9 02
            sta L0072              ; 85 72
            lda L007D              ; A5 7D
            eor L006C              ; 45 6C
            eor L006D              ; 45 6D
            ldx #$88               ; A2 88
            jsr L1335              ; 20 35 13
            lda L0081              ; A5 81
            sta L0072              ; 85 72
            lda L0070              ; A5 70
            clc                    ; 18
            adc L0077              ; 65 77
            sta L0070              ; 85 70
            rts                    ; 60

L1335:      sta L0082              ; 85 82
            stx L0083              ; 86 83
            txa                    ; 8A
            bmi L134A              ; 30 0E
            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11
            sta L007C              ; 85 7C
            tya                    ; 98
            tax                    ; AA
            jsr L11A3              ; 20 A3 11
            sta L0074              ; 85 74
L134A:      lda L0083              ; A5 83
            ldx L0071              ; A6 71
            and #$7F               ; 29 7F
            clc                    ; 18
            adc L007C              ; 65 7C
            sta L007C              ; 85 7C
            bne L1359              ; D0 02
            ldx L0070              ; A6 70
L1359:      lda L0074              ; A5 74
            stx L007B              ; 86 7B
            sec                    ; 38
            sbc L007B              ; E5 7B
            bcs L136B              ; B0 09
            eor #$FF               ; 49 FF
            clc                    ; 18
            adc #$01               ; 69 01
            inc L007C              ; E6 7C
            inc L007C              ; E6 7C
L136B:      sta L0074              ; 85 74
            beq L1394              ; F0 25
            ldx L007C              ; A6 7C
            lda L13AB,X            ; BD AB 13
            sta L0077              ; 85 77
            lda L13AF,X            ; BD AF 13
            sta L0078              ; 85 78
L137B:      lda L0082              ; A5 82
            beq L1382              ; F0 03
            jsr L139C              ; 20 9C 13
L1382:      lda L0070              ; A5 70
            clc                    ; 18
            adc L0077              ; 65 77
            sta L0070              ; 85 70
            lda L0071              ; A5 71
            clc                    ; 18
            adc L0078              ; 65 78
            sta L0071              ; 85 71
            dec L0074              ; C6 74
            bne L137B              ; D0 E7
L1394:      lda L0082              ; A5 82
            beq L139B              ; F0 03
            jsr L139C              ; 20 9C 13
L139B:      rts                    ; 60

L139C:      ldy L0072              ; A4 72
            ldx L09F1,Y            ; BE F1 09
            lda L09F7,Y            ; B9 F7 09
            jsr L13FE              ; 20 FE 13
            jsr L16C4              ; 20 C4 16
            rts                    ; 60

L13AB:      .byte $01,$00,$FF,$00
L13AF:      .byte $00,$01
L13B1:      .byte $00,$FF,$01,$FF,$01,$FF,$01,$01
            .byte $FF,$FF

L13BB:      ldy L0087              ; A4 87
            beq L13CB              ; F0 0C
L13BF:      ldx L0A00,Y            ; BE 00 0A
            lda L46B0,X            ; BD B0 46
            sta L0A09,Y            ; 99 09 0A
            dey                    ; 88
            bne L13BF              ; D0 F4
L13CB:      rts                    ; 60

            sta L0096              ; 85 96
            and #$F0               ; 29 F0
            sta L007B              ; 85 7B
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            ora L007B              ; 05 7B
            sta L0088              ; 85 88
            lda L0096              ; A5 96
            and #$0F               ; 29 0F
            sta L007B              ; 85 7B
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            ora L007B              ; 05 7B
            rts                    ; 60

;--------------------------------------------
; Calculate char data address
; A=chr
;--------------------------------------------

L13E7:      asl A                  ; 0A
            rol L0091              ; 26 91
            asl A                  ; 0A
            rol L0091              ; 26 91
            asl A                  ; 0A
            rol L0091              ; 26 91

	clc
	adc #<L4E00
            sta L0090              ; 85 90

            lda L0091              ; A5 91
            and #$07               ; 29 07
;            clc                    ; 18
            adc #>L4E00               ; 69 4E
            sta L0091              ; 85 91
            ldy #$07               ; A0 07
            rts                    ; 60

;----------------------------------------------
; Plot sprites to build screen
;----------------------------------------------

L13FE:      jsr L13E7              ; 20 E7 13

; Copy sprite data to buffer

            lda L142F,X            ; BD 2F 14
            sta L0089              ; 85 89
L1406:      lda (L0090),Y          ; B1 90
            sta L46A0,Y            ; 99 A0 46
            dey                    ; 88
            bpl L1406              ; 10 F8
;            dey                    ; 88
;            bpl L1406              ; 10 F5

            lda #$0F               ; A9 0F
            sec                    ; 38
            sbc L0071              ; E5 71
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            tax                    ; AA
            lda L0070              ; A5 70
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            jsr L5400              ; 20 00 54

            ldx #$07               ; A0 07
L1424:      lda L46A0,x            ; B9 A0 46
            and L0089              ; 25 89
	ldy scrtab,x
            sta (L0090),Y          ; 91 90
            dex                    ; 88
            bpl L1424              ; 10 F6
            rts                    ; 60

L142F:      .byte $00,$FF,$FF,$FF,$00

L1434:      ldy L0A00,X            ; BC 00 0A
            iny                    ; C8
            lda L46B0,Y            ; B9 B0 46
            dey                    ; 88
            sec                    ; 38
            sbc L46B0,Y            ; F9 B0 46
            cpy #$25               ; C0 25
            bne L1446              ; D0 02

            lda #$02               ; A9 02
L1446:      sta L007B              ; 85 7B
            lda L0A12,X            ; BD 12 0A
            bne L145D              ; D0 10

            lda L0A1B,X            ; BD 1B 0A
            and #$07               ; 29 07
            lsr A                  ; 4A
            ldy L0A2D,X            ; BC 2D 0A
            bmi L146D              ; 30 15

            clc                    ; 18
            adc #$04               ; 69 04
            bpl L146D              ; 10 10

L145D:      lda L0057              ; A5 57
            ldy L0A2D,X            ; BC 2D 0A
            bmi L1466              ; 30 02
            eor #$FF               ; 49 FF

L1466:      clc                    ; 18
            adc L0A24,X            ; 7D 24 0A
            and #$07               ; 29 07
            lsr A                  ; 4A

L146D:      dec L007B              ; C6 7B
            and L007B              ; 25 7B
            clc                    ; 18
            adc L0A09,X            ; 7D 09 0A
            lsr A                  ; 4A
            ror L007B              ; 66 7B
            lsr A                  ; 4A
            ror L007B              ; 66 7B
            lsr A                  ; 4A
            ror L007B              ; 66 7B
            clc                    ; 18

;            adc #$30               ; 69 30
            sta L0093              ; 85 93

            lda L007B              ; A5 7B
            and #$E0               ; 29 E0
            sta L0092              ; 85 92

	clc
	lda L0092
	adc #<L3000
	sta L0092
	lda L0093
	adc #>L3000
	sta L0093

            ldy L0A48,X            ; BC 48 0A
            lda L142F,Y            ; B9 2F 14
            sta L0089              ; 85 89
            txa                    ; 8A
            tay                    ; A8
            ldx L0A24,Y            ; BE 24 0A
            rts                    ; 60

;--------------------------------------------

L1497:      lda L008A              ; A5 8A
            ldy L0A12,X            ; BC 12 0A
            beq L14A1              ; F0 03
            clc                    ; 18
            adc #$09               ; 69 09
L14A1:      tay                    ; A8
            lda L0A2D,X            ; BD 2D 0A
            sta L0A5A,X            ; 9D 5A 0A
            clc                    ; 18
            adc L0A1B,Y            ; 79 1B 0A
            cmp L0A36,X            ; DD 36 0A
            bcc L14B8              ; 90 07
            beq L14B8              ; F0 05
            cmp L0A3F,X            ; DD 3F 0A
            bcc L14C6              ; 90 0E
L14B8:      lda L0A2D,X            ; BD 2D 0A
            eor #$FF               ; 49 FF
            sec                    ; 38
            adc #$00               ; 69 00
            sta L0A2D,X            ; 9D 2D 0A
            lda L0A1B,Y            ; B9 1B 0A
L14C6:      sta L0A1B,Y            ; 99 1B 0A
            rts                    ; 60

L14CA:      ldx L0087              ; A6 87
            beq L14E4              ; F0 16

            stx L008A              ; 86 8A
L14D0:      dec L0A63,X            ; DE 63 0A
            bne L14DE              ; D0 09

            jsr L1434              ; 20 34 14

            jsr L1864              ; 20 64 18
            jsr L181D              ; 20 1D 18

L14DE:      dec L008A              ; C6 8A
            ldx L008A              ; A6 8A
            bne L14D0              ; D0 EC

L14E4:      rts                    ; 60

L14E5:      lda L0069              ; A5 69
            beq L14EF              ; F0 06
            lda #$00               ; A9 00
            sta L0069              ; 85 69
            beq L1504              ; F0 15

L14EF:      ldx #$00               ; Scan-Z
            jsr L54C0              ; 20 C0 54
            and #$FE               ; 29 FE
            sta L008E              ; 85 8E

;	cmp #$fe
;	bne L14EE
;	jsr chk_hitflag
L14EE:
            ldx #$01               ; Scan-X
            jsr L54C0              ; 20 C0 54
            and #$02               ; 29 02
            clc                    ; 18
            adc L008E              ; 65 8E
            sta L008E              ; 85 8E

;	and #2
;	beq L1504	
;	jsr chk_hitflag

L1504:      ldx #$02               ; Scan-RET
            jsr L54C0              ; 20 C0 54
            sta L008B              ; 85 8B

;	beq L1505
;	jsr chk_hitflag
L1505:
            rts                    ; 60

;chk_hitflag:
;	lda hitflag
;	beq L1500
;	dec hitflag
;L1500:
;	rts

;---------------------------------------------

L150C:      lda #$00               ; A9 00
            sta L004C              ; 85 4C

            lda L009F              ; A5 9F
            bne L151A              ; D0 06

            lda L0064              ; A5 64
            ora L0065              ; 05 65
            bne L151D              ; D0 03

L151A:      jsr L14E5              ; 20 E5 14
L151D:      jsr L0B03              ; 20 03 0B
            jsr L1CF7              ; 20 F7 1C

            lda L008E              ; A5 8E
            beq L1536              ; F0 0F
            cmp L0A2D              ; CD 2D 0A
            beq L152F              ; F0 03
            sta L0A2D              ; 8D 2D 0A

L152F:      clc                    ; 18
            adc L0A1B              ; 6D 1B 0A
            sta L0A1B              ; 8D 1B 0A

L1536:      jsr L18E2              ; 20 E2 18
            beq L1544              ; F0 09

            lda L0A1B              ; AD 1B 0A
            sec                    ; 38
            sbc L008E              ; E5 8E
            sta L0A1B              ; 8D 1B 0A

L1544:      ldx #$00               ; A2 00
            jsr L1721              ; 20 21 17
            jsr L1913              ; 20 13 19
            jsr L193A              ; 20 3A 19
            lda L0065              ; A5 65
L1551:      cmp #$07               ; C9 07
            bcs L1599              ; B0 44
            lda L006B              ; A5 6B
            beq L156A              ; F0 11
            lda L008E              ; A5 8E
            beq L156A              ; F0 0D
            ldx L006C              ; A6 6C
            cmp L1ACE,X            ; DD CE 1A
            beq L156A              ; F0 06
            inc L0A24              ; EE 24 0A
            inc L0A24              ; EE 24 0A
L156A:      ldx #$00               ; A2 00
            stx L006B              ; 86 6B
            jsr L1721              ; 20 21 17
            jsr L1743              ; 20 43 17
            ldx L006C              ; A6 6C
            lda L0A1B              ; AD 1B 0A
            and #$07               ; 29 07
            cmp L1ACA,X            ; DD CA 1A
            bne L1599              ; D0 19
            ldy L1ACC,X            ; BC CC 1A
            lda (L0060),Y          ; B1 60
            cmp #$03               ; C9 03
            bne L1599              ; D0 10
            lda L008E              ; A5 8E
            cmp L1ACE,X            ; DD CE 1A
            bne L1599              ; D0 09
            lda L0A24              ; AD 24 0A
            sec                    ; 38
            sbc #$02               ; E9 02
            sta L0A24              ; 8D 24 0A
L1599:      jsr L1A1B              ; 20 1B 1A
            jsr L1A1B              ; 20 1B 1A
            jsr L1A1B              ; 20 1B 1A
            jsr L1BA9              ; 20 A9 1B
            jsr L17BF              ; 20 BF 17
            ldx #$00               ; A2 00
            jsr L1721              ; 20 21 17
            jsr L0B0C              ; 20 0C 0B
            jsr L14CA              ; 20 CA 14
            lda #$B0               ; A9 B0
            sta L547D              ; 8D 7D 54
            dec L009C              ; C6 9C
            beq L15CD              ; F0 11

;            lda #$13               ; A9 13
;            jsr OSBYTE              ; 20 F4 FF

            ldx #$01               ; A2 01
            jsr L1CEE              ; Wait loop

            lda L008C              ; A5 8C
            ldx L008D              ; A6 8D
            jsr L5475              ; 20 75 54
L15CD:      jsr L14CA              ; 20 CA 14
            jsr L0B0F              ; 20 0F 0B
            jsr L54C9              ; 20 C9 54
            jsr L4200              ; 20 00 42
            lda #$90               ; A9 90
            sta L547D              ; 8D 7D 54
            dec L009C              ; C6 9C
            bpl L15F7              ; 10 15
            ldx #$00               ; A2 00
            jsr L1434              ; 20 34 14
            lda L0A1B              ; AD 1B 0A
            and #$F8               ; 29 F8
            sta L008C              ; 85 8C
            stx L008D              ; 86 8D
            ldx L008D              ; A6 8D
            bmi L15F7              ; 30 03
            jsr L545F              ; 20 5F 54
L15F7:      ldx #$00               ; A2 00
            stx L009C              ; 86 9C
            jsr L1721              ; 20 21 17
            jsr L1958              ; 20 58 19
            jsr L1AEE              ; 20 EE 1A
            lda L0063              ; A5 63
            beq L1636              ; F0 2E

;            lda #$10               ; A9 10
;            jsr L0B27              ; Sound

;            lda #$28               ; A9 28
;            jsr L0B27              ; Sound

; Death sound

	lda #10
	sta tmpnote
L15F8:
	lda tmpnote
	ldy #60
	jsr L0B27		; Make death high note sound
	lda tmpnote
	ora #32
	ldy #40
	jsr L0B27		; Make death low note sound
	inc tmpnote
	lda tmpnote
	cmp #20
	bne L15F8

.if cheat<>2
            dec L009B              ; C6 9B
.endif

            lda L1127              ; AD 27 11
            sta L0A2D              ; 8D 2D 0A
            lda L1128              ; AD 28 11
            sta L0A1B              ; 8D 1B 0A
            lda L1129              ; AD 29 11
            sta L0A24              ; 8D 24 0A
            lda #$00               ; A9 00
            sta L009A              ; 85 9A
            sta L0064              ; 85 64
            sta L0065              ; 85 65
            jsr L1B79              ; 20 79 1B
            lda L112A              ; AD 2A 11
            sta L0055              ; 85 55
L1636:      jsr L1D10              ; 20 10 1D
            rts                    ; 60

tmpnote:	.byte 0

;---------------------------------------------


L163A:      .byte $00
L163B:      .byte $04,$04,$04,$04,$02,$02,$02
            .byte $00,$00,$00,$00,$FE,$FE,$FE,$FE
            .byte $FC,$FC,$FC

L164D:      ldx #$03               ; A2 03
            jsr L11A3              ; 20 A3 11
            sta L0087              ; 85 87
            tay                    ; A8
            beq L16BA              ; F0 63
L1657:      ldx #$06               ; A2 06
            jsr L11A3              ; 20 A3 11
            sta L0A00,Y            ; 99 00 0A
            ldx #$05               ; A2 05
            jsr L16BD              ; 20 BD 16
            sta L0A1B,Y            ; 99 1B 0A
            ldx #$04               ; A2 04
            jsr L16BD              ; 20 BD 16
            sta L0A24,Y            ; 99 24 0A
            ldx #$05               ; A2 05
            jsr L16BD              ; 20 BD 16
            sta L0A36,Y            ; 99 36 0A
            ldx #$05               ; A2 05
            jsr L16BD              ; 20 BD 16
            sta L0A3F,Y            ; 99 3F 0A
            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11
            asl A                  ; 0A
            beq L1689              ; F0 02
            lda #$FF               ; A9 FF
L1689:      sta L0A12,Y            ; 99 12 0A
            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11
            sta L0097              ; 85 97
            ldx #$03               ; A2 03
            jsr L11A3              ; 20 A3 11
            sta L0A2D,Y            ; 99 2D 0A
            ldx L0097              ; A6 97
            bne L16A7              ; D0 08
            eor #$FF               ; 49 FF
            clc                    ; 18
            adc #$01               ; 69 01
            sta L0A2D,Y            ; 99 2D 0A
L16A7:      ldx #$02               ; A2 02
            jsr L11A3              ; 20 A3 11
            sta L0A48,Y            ; 99 48 0A
            lda #$00               ; A9 00
            sta L0A5A,Y            ; 99 5A 0A
            sta L0A51,Y            ; 99 51 0A
            dey                    ; 88
            bne L1657              ; D0 9D
L16BA:      jmp L13BB              ; 4C BB 13

L16BD:      jsr L11A3              ; 20 A3 11
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            rts                    ; 60

;--------------------------------------------
; Set tile in shadowscreen (L4400-L45FF)
; X x Y = 32 x 16
;
; Y/X 00: 01: 02: 03:           31:
; 15: 000 001 002 003 ......... 01f
; 14: 020 021 022 023 ......... 02f
;          .....                ..
; 00: 1e0 1e1 1e2 1e3 ......... 1ff
;
; L0070 = X
; L0071 = Y
; L0072 = Tilenr
;
; L0090/91 = Screen address
;
; L0060/61 = Shadowscreen address
;--------------------------------------------

; Calculate relative shadowscreen address

L16C4:      ldy #0               ; A0 22
            sty L0061              ; 84 61
            lda #$0F               ; A9 0F
            sec                    ; 38
            sbc L0071              ; E5 71
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            asl A                  ; 0A
            rol L0061              ; 26 61
            adc L0070              ; 65 70
            sta L0060              ; 85 60

; Add shadowscreen baseaddress to relative address

	clc			
	lda L0060
	adc #<L4400
	sta L0060
	lda L0061
	adc #>L4400
	sta L0061

; Check tilenr

            lda L0072              ; A5 72
            adc #$01               ; 69 01
            cmp #$05               ; C9 05
            bcc L16FF              ; 90 1F
            beq L16FD              ; F0 1B

            inc L0066              ; E6 66
            ldx L0066              ; A6 66

; Save screenaddress

            lda L0090              ; A5 90
            sta L0A8C,X            ; 9D 8C 0A
            lda L0091              ; A5 91
            sta L0A98,X            ; 9D 98 0A

; Save Shadowscreen address

            lda L0060              ; A5 60
            sta L0AA8,X            ; 9D A8 0A
            lda L0061              ; A5 61
            sta L0AB4,X            ; 9D B4 0A

; Adjust tilenr

            txa                    ; 8A
            ora #$10               ; 09 10

L16FD:      ora #$C0               ; 09 C0

; Set tilenr in shadowscreen

L16FF:      tay                    ; A8
            cmp #$04               ; C9 04
            bne L170D              ; D0 09

            lda L0077              ; A5 77
            asl A                  ; 0A
            cmp L006A              ; C5 6A
            beq L170D              ; F0 02

            ldy #$14               ; A0 14
L170D:      tya                    ; 98
            ldy #$00               ; A0 00
            sta (L0060),Y          ; 91 60
            rts                    ; 60

;--------------------------------------------
; Reset shadowscreen
;--------------------------------------------

L1713:      ldy #$00               ; A0 00
            lda #$80               ; A9 80
L1717:      sta L4400,Y            ; 99 00 44
            sta L4500,Y            ; 99 00 45
            iny                    ; C8
            bne L1717              ; D0 F7
            rts                    ; 60

;--------------------------------------------

L1721:      lda #$00               ; A9 22
            sta L0061              ; 85 61
            lda L0A24,X            ; BD 24 0A
            sec                    ; 38
            sbc #$08               ; E9 08
            bcs L172F              ; B0 02
            dec L0061              ; C6 61
L172F:      asl A                  ; 0A
            asl A                  ; 0A
            rol L0061              ; 26 61
            and #$E0               ; 29 E0
            sta L007B              ; 85 7B
            lda L0A1B,X            ; BD 1B 0A
            lsr A                  ; 4A
            lsr A                  ; 4A
            lsr A                  ; 4A
            clc                    ; 18
            adc L007B              ; 65 7B
            sta L0060              ; 85 60

	clc
	lda L0060
	adc #<L4400
	sta L0060
	lda L0061
	adc #>L4400
	sta L0061
	lda L0060
	sta L007B

            rts                    ; 60

;--------------------------------------------

L1743:      ldx L006C              ; A6 6C
            ldy L1AD0,X            ; BC D0 1A
            lda (L0060),Y          ; B1 60
            beq L174E              ; F0 02
            bpl L1758              ; 10 0A
L174E:      inx                    ; E8
            ldy L1AD0,X            ; BC D0 1A
            lda (L0060),Y          ; B1 60
            beq L17A2              ; F0 4C
            bmi L17A2              ; 30 4A
L1758:      cmp #$03               ; C9 03
            bne L1763              ; D0 07
            jsr L1A6C              ; 20 6C 1A
            beq L17A2              ; F0 41
            bpl L1770              ; 10 0D
L1763:      sta L007B              ; 85 7B
            lda L0A24              ; AD 24 0A
            and #$07               ; 29 07
            cmp #$03               ; C9 03
            bcs L17A2              ; B0 34
            lda L007B              ; A5 7B
L1770:      and #$07               ; 29 07
            cmp #$04               ; C9 04
            bne L1779              ; D0 03
            jsr L1AD3              ; 20 D3 1A
L1779:      lda L0064              ; A5 64
            beq L1795              ; F0 18
            lda L009A              ; A5 9A
            bne L178D              ; D0 0C
            lda L0A24              ; AD 24 0A
            sec                    ; 38
            sbc L0062              ; E5 62
            bmi L178F              ; 30 06
            cmp #$21               ; C9 21
            bcc L178F              ; 90 02
L178D:

.if cheat<>1
            inc L0063              ; E6 63
.endif
;	lda #1
;	sta $9b00

L178F:      lda #$00               ; A9 00
            sta L0065              ; 85 65
            sta L0064              ; 85 64
L1795:      lda L006B              ; A5 6B
            bne L17A1              ; D0 08
            lda L0A24              ; AD 24 0A
            and #$F8               ; 29 F8
            sta L0A24              ; 8D 24 0A
L17A1:      rts                    ; 60

L17A2:      lda L0065              ; A5 65
            bne L17BE              ; D0 18
            lda L0064              ; A5 64
            bne L17B1              ; D0 07
            lda L0A24              ; AD 24 0A
            sta L0062              ; 85 62
            sta L0064              ; 85 64
L17B1:      lda #$00               ; A9 00
            sta L008E              ; 85 8E
            lda L0A24              ; AD 24 0A
            clc                    ; 18
            adc #$04               ; 69 04
            sta L0A24              ; 8D 24 0A
L17BE:      rts                    ; 60

;--------------------------------------------
; L0060/61 = Shadowscreen address
;--------------------------------------------

L17BF:      lda L0087              ; A5 87
            beq L181C              ; F0 59

            sta L008A              ; 85 8A
L17C5:      ldx L008A              ; A6 8A
            jsr L1497              ; 20 97 14

            lda #$01               ; A9 01
            sta L0A63,X            ; 9D 63 0A

            lda #$00               ; A9 00
            sta L0A6C,X            ; 9D 6C 0A
            jsr L1721              ; 20 21 17

            ldy L0A51,X            ; BC 51 0A
            sty L007B              ; 84 7B
            cmp L0A51,X            ; DD 51 0A
            beq L1818              ; F0 37

            inc L0A6C,X            ; FE 6C 0A
            sta L0A51,X            ; 9D 51 0A
            txa                    ; 8A
            ora #$80               ; 09 80
            ldy #$20               ; A0 20
            sta (L0060),Y          ; 91 60

            iny                    ; C8
            sta (L0060),Y          ; 91 60

            ldy #$40               ; A0 40
            sta (L0060),Y          ; 91 60

            iny                    ; C8
            sta (L0060),Y          ; 91 60

            lda L007B              ; A5 7B
            beq L1818              ; F0 1C

            lda L0A5A,X            ; BD 5A 0A
            beq L1818              ; F0 17
            asl A                  ; 0A
            lda L0A12,X            ; BD 12 0A
            and #$02               ; 29 02
            adc #$00               ; 69 00
            tax                    ; AA
            ldy L185C,X            ; BC 5C 18

            lda L004E              ; A5 4E
            sta (L0060),Y          ; 91 60

            ldy L1860,X            ; BC 60 18
            sta (L0060),Y          ; 91 60
            ldx L008A              ; A6 8A

L1818:      dec L008A              ; C6 8A
            bne L17C5              ; D0 A9

L181C:      rts                    ; 60

;--------------------------------------------
; Wipe sprites
;
; L008A = 0/1/2
;--------------------------------------------

L181D:      ldx L008A              ; A6 8A
            lda L0A6C,X            ; BD 6C 0A
            beq L185B              ; F0 37

            lda L0A12,X            ; BD 12 0A
            bne L185B              ; D0 32

            lda #$00               ; A9 00
            sta L0095              ; 85 95

            lda #$0F               ; A9 0F
            sta L0094              ; 85 94

            lda #$F8               ; A9 F8
            ldy L0A5A,X            ; BC 5A 0A
            bpl L183A              ; 10 02

            lda #$0C               ; A9 0C
L183A:      clc                    ; 18
            adc L0A1B,X            ; 7D 1B 0A
            sta L007B              ; 85 7B

; Wipe sprite 16x8

            lda #<L4600               ; A9 00
            sta L0092              ; 85 92
            lda #>L4600               ; A9 46
            sta L0093              ; 85 93

            lda L0A24,X            ; BD 24 0A
            tax                    ; AA
            lda L007B              ; A5 7B
            jsr L5422              ; 20 22 54

            lda #$08               ; A9 08
            sta L0095              ; 85 95

            lda #$1F               ; A9 1F
            sta L0094              ; 85 94

            ldx L008A              ; A6 8A

L185B:      rts                    ; 60

;--------------------------------------------

L185C:      .byte $1F,$22,$00,$60
L1860:      .byte $3F,$42,$01,$61

;--------------------------------------------
; Check if vertical sprite is moving up or down
;
; Wipe top for sprite moving down and
; Wipe bottom for sprite moving up
;
; Y = sprite nr
;--------------------------------------------

L1864:      lda L0A12,Y            ; B9 12 0A
L1867:      beq L18A9              ; F0 40

            lda L0A5A,Y            ; B9 5A 0A
            bmi L18B2              ; 30 44

; Vert.sprite is moving down

            ldx L0A00,Y            ; BE 00 0A
            sta L007B              ; 85 7B
            asl A                  ; 0A
            sbc #$00               ; E9 00
            sta L0094              ; 85 94

            lda L0092              ; A5 92
            sta L0097              ; 85 97
            lda L0093              ; A5 93
            sta L0096              ; 85 96

; Wipe sprite 16x8

            lda #<L4600               ; A9 00
            sta L0092              ; 85 92
            lda #>L4600               ; A9 46
            sta L0093              ; 85 93

            lda L0A24,Y            ; B9 24 0A
            sec                    ; 38
;            sbc L007B              ; E5 7B
	sbc #8

            tax                    ; AA
            lda L0A1B,Y            ; B9 1B 0A
            jsr L5422              ; 20 22 54

	inc L0091

            lda L0096              ; A5 96
            sta L0093              ; 85 93

            lda #$1F               ; A9 1F
            sta L0094              ; 85 94

; plot sprite 16x16

            lda L0097              ; A5 97
            sta L5434+1              ; 8D 35 54
	sta L5461+1
            jsr L18D8              ; 20 D8 18

            rts                    ; 60

L18A6:
            ldx L0A24,Y            ; BE 24 0A
L18A9:      lda L0A1B,Y            ; B9 1B 0A
            and #$F8               ; 29 F8
            jsr L5422              ; 20 22 54
            rts                    ; 60

; Vert.sprite is moving up

L18B2:      lda L0A1B,Y            ; B9 1B 0A
            jsr L5422              ; 20 22 54

            lda #<L4600               ; A9 00
            sta L5434+1              ; 8D 35 54
	sta L5461+1

            lda #>L4600               ; A9 46
            sta L0093              ; 85 93

            ldy L008A              ; A4 8A
            lda L0A5A,Y            ; B9 5A 0A

            eor #$FF               ; 49 FF
            clc                    ; 18
            adc #$01               ; 69 01
            asl A                  ; 0A
	pha
            sbc #$00               ; E9 00
            sta L0094              ; 85 94

	pla			; Set wipe screen address
	lsr a
	tay
	clc
	lda L0090
	adc scrtab,y
	sta L0090
	lda L0091
	adc #0
	sta L0091	
 
           jsr L18D8              ; 20 D8 18

            lda #$1F               ; A9 1F
            sta L0094              ; 85 94

            rts                    ; 60

L18D8:      ldx L0094              ; A6 94
            lda L0093              ; A5 93
            sta L5434+2              ; 8D 36 54
	sta L5461+2
            jmp L5445              ; 4C 45 54

;--------------------------------------------

L18E2:      ldx #$00               ; A2 00
            stx L0096              ; 86 96
            jsr L1721              ; 20 21 17
            ldy #$20               ; A0 20
            lda L008E              ; A5 8E
            beq L1902              ; F0 13
            bmi L18F2              ; 30 01
            iny                    ; C8
L18F2:      jsr L1905              ; 20 05 19
            jsr L1905              ; 20 05 19
            lda L0A24              ; AD 24 0A
            and #$07               ; 29 07
            beq L1902              ; F0 03
            jsr L1905              ; 20 05 19
L1902:      lda L0096              ; A5 96
            rts                    ; 60

L1905:      lda (L0060),Y          ; B1 60
            cmp #$02               ; C9 02
            bne L190D              ; D0 02
            inc L0096              ; E6 96
L190D:      tya                    ; 98
            clc                    ; 18
            adc #$20               ; 69 20
            tay                    ; A8
            rts                    ; 60

L1913:      lda L008B              ; A5 8B
            beq L1939              ; F0 22
            inc L0064              ; E6 64
            lda #$12               ; A9 12
            sta L0065              ; 85 65
            inc L008B              ; E6 8B
            lda L0A24              ; AD 24 0A
            and #$FC               ; 29 FC
            sta L0A24              ; 8D 24 0A
            sec                    ; 38
            sbc #$08               ; E9 08
            sta L0062              ; 85 62
            jsr L193A              ; 20 3A 19
            beq L1939              ; F0 08

;            lda #$08               ; A9 08
;            jsr L0B27              ; 20 27 0B

            jsr L1CF7              ; 20 F7 1C
L1939:      rts                    ; 60

L193A:      lda L0A24              ; AD 24 0A
            and #$07               ; 29 07
            bne L1957              ; D0 16
            ldy #$00               ; A0 00
            lda (L0060),Y          ; B1 60
            eor #$02               ; 49 02
            beq L1950              ; F0 07
            iny                    ; C8
            lda (L0060),Y          ; B1 60
            eor #$02               ; 49 02
            bne L1957              ; D0 07
L1950:      jsr L1CF7              ; 20 F7 1C
            lda #$00               ; A9 00
            sta L0065              ; 85 65
L1957:      rts                    ; 60
L1958:      lda L0A24              ; AD 24 0A
            ora #$07               ; 09 07
            sec                    ; 38
            sbc L0A24              ; ED 24 0A
            sta L0096              ; 85 96
            ldy #$20               ; A0 20
            lda #$1E               ; A9 1E
            jsr L1972              ; 20 72 19
            ldy #$21               ; A0 21
            lda #$1F               ; A9 1F
            jsr L1972              ; 20 72 19
            rts                    ; 60
L1972:      sta L0097              ; 85 97
            ldx L0096              ; A6 96
            jsr L198B              ; 20 8B 19
            ldx #$07               ; A2 07
            jsr L198B              ; 20 8B 19
            lda #$07               ; A9 07
            sec                    ; 38
            sbc L0096              ; E5 96
            beq L198A              ; F0 05
            tax                    ; AA
            dex                    ; CA
            jsr L198B              ; 20 8B 19
L198A:      rts                    ; 60
L198B:      tya                    ; 98
            clc                    ; 18
            adc #$20               ; 69 20
            sta L007B              ; 85 7B
            lda (L0060),Y          ; B1 60
            sta L0068              ; 85 68
            bpl L19AB              ; 10 14
            ldy L0097              ; A4 97
L1999:      lda L4620,Y            ; B9 20 46
            beq L19A1              ; F0 03
            jsr L19B8              ; 20 B8 19
L19A1:      dey                    ; 88
            dey                    ; 88
            dex                    ; CA
            bpl L1999              ; 10 F3
            sty L0097              ; 84 97
            ldy L007B              ; A4 7B
            rts                    ; 60
L19AB:      inx                    ; E8
            txa                    ; 8A
            asl A                  ; 0A
            eor #$FF               ; 49 FF
            sec                    ; 38
            adc L0097              ; 65 97
            sta L0097              ; 85 97
            ldy L007B              ; A4 7B
            rts                    ; 60
L19B8:      stx L0070              ; 86 70
            sty L0071              ; 84 71
            lda #$00               ; A9 00
            sta L4620,Y            ; 99 20 46
            lda L0068              ; A5 68
            and #$7F               ; 29 7F
            beq L19EB              ; F0 24
            cmp #$4E               ; C9 4E
            bcs L19D7              ; B0 0C
            jsr L19F3              ; 20 F3 19
            beq L19D2              ; F0 02

.if cheat<>1
            inc L0063              ; E6 63
.endif
;	lda #2
;	sta $9b00

L19D2:      ldx L0070              ; A6 70
            ldy L0071              ; A4 71
            rts                    ; 60
L19D7:      and #$0F               ; 29 0F
            tax                    ; AA
            lda L0A80,X            ; BD 80 0A
            beq L19D2              ; F0 F3
            lda #$00               ; A9 00
            sta L0A80,X            ; 9D 80 0A
            stx L0067              ; 86 67
            jsr L0B06              ; 20 06 0B
            bpl L19D2              ; 10 E7
L19EB:      lda L006F              ; A5 6F
            bne L19D2              ; D0 E3

.if cheat<>1
            inc L0063              ; E6 63
.endif
;	lda #3
;	sta $9b00

L19F2:
            bne L19D2              ; D0 DF
L19F3:      tax                    ; AA
            lda L0A00,X            ; BD 00 0A
            cmp #$06               ; C9 06
            bne L1A18              ; D0 1D
            lda L0A25              ; AD 25 0A
            sec                    ; 38
            sbc L0A24              ; ED 24 0A
            bcc L1A18              ; 90 14
            cmp #$06               ; C9 06
            bcc L1A18              ; 90 10
            lda L0A25              ; AD 25 0A
            sec                    ; 38
            sbc #$10               ; E9 10
            and #$FE               ; 29 FE
            sta L0A24              ; 8D 24 0A
            lda #$00               ; A9 00
            sta L0064              ; 85 64
            rts                    ; 60
L1A18:      lda #$01               ; A9 01
            rts                    ; 60
L1A1B:      ldx L0066              ; A6 66
            bmi L1A6B              ; 30 4C
            cpx L0067              ; E4 67
            bcc L1A63              ; 90 40
            ldx L0067              ; A6 67
            lda L0A8C,X            ; BD 8C 0A
            sta L0090              ; 85 90
            lda L0A98,X            ; BD 98 0A
            sta L0091              ; 85 91
            ldy L0A80,X            ; BC 80 0A
            beq L1A41              ; F0 0D
            dec L0A80,X            ; DE 80 0A
            bne L1A3E              ; D0 05
            lda #$04               ; A9 04
            sta L0A80,X            ; 9D 80 0A
L1A3E:      ldy L0A80,X            ; BC 80 0A
L1A41:      lda L142F,Y            ; B9 2F 14
            sta L0089              ; 85 89

; Plot char

	stx x_tmp
            ldx #$07               ; A0 07
L1A48:
	ldy scrtab,x
            lda L46A0,x            ; B9 A0 46
            and L0089              ; 25 89
            sta (L0090),Y          ; 91 90
            dex                    ; 88
            bpl L1A48              ; 10 F6

	ldx x_tmp
            lda L0AA8,X            ; BD A8 0A
            sta L0090              ; 85 90
            lda L0AB4,X            ; BD B4 0A
            sta L0091              ; 85 91

            txa                    ; 8A
            ora #$E0               ; 09 E0
            ldy #$00               ; A0 00
            sta (L0090),Y          ; 91 90
L1A63:      dec L0067              ; C6 67
            bpl L1A6B              ; 10 04
            lda #$08               ; A9 08
            sta L0067              ; 85 67
L1A6B:      rts                    ; 60
L1A6C:      inc L004C              ; E6 4C
            ldx L006C              ; A6 6C
            tya                    ; 98
            cmp L1AD0,X            ; DD D0 1A
            bne L1AC3              ; D0 4D
            inc L006B              ; E6 6B
            lda L0A24              ; AD 24 0A
            and #$07               ; 29 07
            sta L007B              ; 85 7B
            lda L0A1B              ; AD 1B 0A
            and #$07               ; 29 07
            eor L1AC6,X            ; 5D C6 1A
            sec                    ; 38
            adc L1AC8,X            ; 7D C8 1A
            bmi L1A99              ; 30 0C
            cmp L007B              ; C5 7B
            bcc L1A99              ; 90 08
            dec L0A24              ; CE 24 0A
            dec L0A24              ; CE 24 0A
            bcs L1AC0              ; B0 27
L1A99:      clc                    ; 18
            adc #$04               ; 69 04
            cmp L007B              ; C5 7B
            bcc L1AC0              ; 90 20
            sbc #$02               ; E9 02
            sta L007B              ; 85 7B
            lda L0A24              ; AD 24 0A
            and #$F8               ; 29 F8
            ora L007B              ; 05 7B
            sbc #$01               ; E9 01
            sta L0A24              ; 8D 24 0A
            lda #$01               ; A9 01
            ldx L0055              ; A6 55
            cpx #$16               ; E0 16
            beq L1ABC              ; F0 04
            cpx #$1D               ; E0 1D
            bne L1ABE              ; D0 02
L1ABC:      lda #$04               ; A9 04
L1ABE:      tax                    ; AA
            rts                    ; 60
L1AC0:      lda #$00               ; A9 00
            rts                    ; 60
L1AC3:      lda #$FF               ; A9 FF
            rts                    ; 60
L1AC6:      .byte $FF,$00
L1AC8:      .byte $05,$FE
L1ACA:      .byte $00,$06
L1ACC:      .byte $41,$40
L1ACE:      .byte $02,$FE
L1AD0:      .byte $61,$60,$61
L1AD3:      .byte $85,$4C
            lda L006A              ; A5 6A
            ldx L007B              ; A6 7B
            cpx #$14               ; E0 14
            bne L1AE1              ; D0 04
            eor #$FF               ; 49 FF
            adc #$00               ; 69 00
L1AE1:      ldx L008E              ; A6 8E
            beq L1AE9              ; F0 04
            cmp L008E              ; C5 8E
            bne L1AED              ; D0 04
L1AE9:      sta L008E              ; 85 8E
            sta L0069              ; 85 69
L1AED:      rts                    ; 60
L1AEE:      ldy #$00               ; A0 00
            lda L0A1B              ; AD 1B 0A
            beq L1B1C              ; F0 27
            iny                    ; C8
            cmp #$F6               ; C9 F6
            beq L1B1C              ; F0 22
            iny                    ; C8
            ldx #$68               ; A2 68
            lda L0A24              ; AD 24 0A
            bmi L1B24              ; 30 22
            iny                    ; C8
            ldx #$01               ; A2 01
            cmp #$71               ; C9 71
            bcc L1B3A              ; 90 31
            lda L0064              ; A5 64
            beq L1B24              ; F0 17
            lda L0A24              ; AD 24 0A
            sec                    ; 38
            sbc L0062              ; E5 62
            cmp #$22               ; C9 22
            bcc L1B24              ; 90 0D
            sta L009A              ; 85 9A
            jmp L1B24              ; 4C 24 1B
L1B1C:      eor #$F4               ; 49 F4
            sta L0A1B              ; 8D 1B 0A
            jmp L1B2B              ; 4C 2B 1B
L1B24:      stx L0A24              ; 8E 24 0A
            lda #$00               ; A9 00
            sta L008E              ; 85 8E
L1B2B:      lda L0AA4,Y            ; B9 A4 0A

L1B2E:      sta L0096              ; 85 96
            jsr L1B79              ; 20 79 1B
            lda L0096              ; A5 96
            sta L0055              ; 85 55
            jsr L111B              ; 20 1B 11
L1B3A:      rts                    ; 60

;--------------------------------------------
;--------------------------------------------

L1B3B:      ldx L0055              ; Roomnr
            lda L4180,X            ; BD 80 41
            sta L007B              ; 85 7B

            ldx #$07               ; A2 07
L1B44:      lda #$00               ; A9 00
            lsr L007B              ; 46 7B
            rol A                  ; 2A
            sta L0A80,X            ; 9D 80 0A
            dex                    ; CA
            bpl L1B44              ; 10 F5

            ldy #$00               ; A0 00
L1B51:      ldx #$07               ; A2 07
            jsr L11A3              ; 20 A3 11
            sta L0AA4,Y            ; 99 A4 0A
            iny                    ; C8
            cpy #$04               ; C0 04
            bne L1B51              ; D0 F3

            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11

            asl A                  ; 0A
            asl A                  ; 0A
            sec                    ; 38
            sbc #$02               ; E9 02
            sta L006A              ; 85 6A

            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11
            sta L006C              ; 85 6C

            ldx #$01               ; A2 01
            jsr L11A3              ; 20 A3 11
            sta L006F              ; 85 6F

            rts                    ; 60

;--------------------------------------------

L1B79:      ldx #$07               ; A2 07
L1B7B:      ldy L0A80,X            ; BC 80 0A
            cpy #$01               ; C0 01
            ror A                  ; 6A
            dex                    ; CA
            bpl L1B7B              ; 10 F7
            ldy L0055              ; A4 55
            sta L4180,Y            ; 99 80 41
            rts                    ; 60
L1B8A:      lda #$FF               ; A9 FF
            ldx #$7F               ; A2 7F
L1B8E:      sta L4180,X            ; 9D 80 41
            dex                    ; CA
            bne L1B8E              ; D0 FA
            rts                    ; 60

;--------------------------------------------
; Set address leveldata with X as pointer in 50/51
;--------------------------------------------

L1B95:      lda #$00               ; A9 00
            sta L0052              ; 85 52
            sta L0053              ; 85 53

            lda L1E50,X            ; BD 50 1E
;            clc                    ; 18
;            adc #$1E               ; 69 1E
            sta L0051              ; 85 51
            lda L1E00,X            ; BD 00 1E
            sta L0050              ; 85 50
            rts                    ; 60

;--------------------------------------------
; Scroll 2 lines in tile 4
;--------------------------------------------

L1BA9:      lda L0056              ; A5 56
            beq L1BDA              ; F0 2D

            lda L0057              ; A5 57
            and #$07               ; 29 07
            tax                    ; AA

            lda L0058              ; A5 58
            sta L007B              ; 85 7B

            lda L0059              ; A5 59
            sta L0090              ; 85 90
            lda L005A              ; A5 5A
            sta L0091              ; 85 91

            ldy #$00               ; A0 00
            clc                    ; 18
L1BC1:      lda L4680,X            ; BD 80 46
            sta (L0090),Y          ; 91 90
	tya
	clc
	adc #$40
	tay
;            iny                    ; C8
;            iny                    ; C8
            lda L4688,X            ; BD 88 46
            sta (L0090),Y          ; 91 90
            tya                    ; 98
;            adc #$06               ; 69 06
	clc
	adc #$c1
            tay                    ; A8
;            bne L1BD6              ; D0 03
;            inc L0091              ; E6 91
;            clc                    ; 18
L1BD6:      dec L007B              ; C6 7B
            bne L1BC1              ; D0 E7
L1BDA:      rts                    ; 60

;--------------------------------------------
; Locate tile 4 in shadowscreen
; Address return on L0059/5A
;--------------------------------------------

L1BDB:      ldy #<L4400               ; A0 00
            sty L0060              ; 84 60
            lda #>L4400               ; A9 44
            sta L0061              ; 85 61

            ldy #$00
	    sty L0056              ; 84 56
	sty L007B

L1BE5:      jsr L1C2F              ; 20 2F 1C
            bmi L1C27              ; 30 3D
            bne L1BE5              ; D0 F9

            sty L0059              ; 84 59

;            lda L0061              ; A5 61
;            and #$01               ; 29 01

;            asl L0059              ; 06 59
;            rol A                  ; 2A
;            sta L007B              ; 85 7B
;            ldx L0059              ; A6 59
;            stx L0096              ; 86 96
;            asl L0059              ; 06 59
;            rol A                  ; 2A
;            asl L0059              ; 06 59
;            rol A                  ; 2A
;            sta L0097              ; 85 97
;            lda L0096              ; A5 96
;            and #$C0               ; 29 C0
;            clc                    ; 18
;            adc #$20               ; 69 20
;            adc L0059              ; 65 59
;            sta L0059              ; 85 59
;            lda L0097              ; A5 97
;            adc L007B              ; 65 7B
;            adc #$5D               ; 69 5D
;            sta L005A              ; 85 5A
	lda L0059
	asl a
	rol L007B
	asl a
	rol L007B
	asl a
	rol L007B
	clc
	lda L007B
	adc #$80
	sta L005A

	tya
	and #31
	sta L0059

            ldx #$00               ; A2 00
L1C18:      inx                    ; E8
            jsr L1C2F              ; 20 2F 1C
            bmi L1C28              ; 30 0A
            beq L1C18              ; F0 F8
L1C20:      jsr L1C2F              ; 20 2F 1C
            bmi L1C28              ; 30 03
            bne L1C20              ; D0 F9
L1C27:      rts                    ; 60

L1C28:      stx L0058              ; 86 58
            inc L0056              ; E6 56
            jmp L1C48              ; 4C 48 1C

L1C2F:      iny                    ; C8
            bne L1C3D              ; D0 0B
            inc L0061              ; E6 61
	inc L007B
            lda L0061              ; A5 61
            cmp #>L4600               ; C9 46
            bne L1C3D              ; D0 03
            lda #$FF               ; A9 FF
            rts                    ; 60

L1C3D:      lda (L0060),Y          ; B1 60
            and #$87               ; 29 87
            cmp #$04               ; C9 04
            beq L1C47              ; F0 02
            lda #$01               ; A9 01
L1C47:      rts                    ; 60

L1C48:      lda L09FA              ; AD FA 09
            jsr L13E7              ; 20 E7 13
            ldy #$00               ; A0 00
            lda L006A              ; A5 6A
            bmi L1C5B              ; 30 07
            ldx #$00               ; A2 00
            jsr L1C73              ; 20 73 1C
            bmi L1C60              ; 30 05
L1C5B:      ldx #$07               ; A2 07
            jsr L1C84              ; 20 84 1C
L1C60:      ldy #$02               ; A0 02
            lda L006A              ; A5 6A
            bmi L1C6D              ; 30 07
            ldx #$0F               ; A2 0F
            jsr L1C84              ; 20 84 1C
            bmi L1C72              ; 30 05
L1C6D:      ldx #$08               ; A2 08
            jsr L1C73              ; 20 73 1C
L1C72:      rts                    ; 60

L1C73:      lda (L0090),Y          ; B1 90
            sta L0097              ; 85 97
            lda #$07               ; A9 07
            sta L007A              ; 85 7A
L1C7B:      jsr L1C95              ; 20 95 1C
            inx                    ; E8
            dec L007A              ; C6 7A
            bpl L1C7B              ; 10 F8
            rts                    ; 60

L1C84:      lda (L0090),Y          ; B1 90
            sta L0097              ; 85 97
            lda #$07               ; A9 07
            sta L007A              ; 85 7A
L1C8C:      jsr L1C95              ; 20 95 1C
            dex                    ; CA
            dec L007A              ; C6 7A
            bpl L1C8C              ; 10 F8
            rts                    ; 60

L1C95:      clc                    ; 18
            lda L0097              ; A5 97
            bpl L1C9B              ; 10 01
            sec                    ; 38
L1C9B:      rol A                  ; 2A
            sta L0097              ; 85 97
            sta L4680,X            ; 9D 80 46
            rts                    ; 60

;--------------------------------------------
; Animate foot
;--------------------------------------------

L1CA2:      lda #$28               ; A9 28
            sta L0884              ; 8D 84 08
            ldx #$00               ; A2 00
            jsr L1B95              ; 20 95 1B
            jsr L164D              ; 20 4D 16
            lda #$90               ; A9 C0
            sta L0A0B              ; 8D 0B 0A
            lda #$01               ; A9 01
            sta L0A64              ; 8D 64 0A
            sta L0A65              ; 8D 65 0A
            sta L0A66              ; 8D 66 0A

            jsr L14CA              ; Plot Barrel, foot and Willy

            lda #>L3000               ; A9 30
            sta L0093              ; 85 93
            lda #<L3000               ; A9 00
            sta L0092              ; 85 92

L1CCA:      lda L0A1C              ; AD 1C 0A
            ldx L0A25              ; AE 25 0A
            jsr L5422              ; 20 22 54
            inc L0884              ; EE 84 08
            inc L0884              ; EE 84 08

;            lda #$00               ; A9 00
	lda L0A25
	eor #$ff
	lsr a
	ldy #7
            jsr L0B27              ; Sound

            ldx #$0F               ; A2 0F
            jsr L1CEE              ; Wait loop

            inc L0A25              ; EE 25 0A
            lda L0A25              ; AD 25 0A
            cmp #$61               ; C9 61
            bne L1CCA              ; D0 DD
            rts                    ; 60

;--------------------------------------------
; Wait loop
;--------------------------------------------

L1CEE:      ldy #$00               ; A0 00
L1CF0:      dey                    ; 88
            bne L1CF0              ; D0 FD
            dex                    ; CA
            bne L1CF0              ; D0 FA
            rts                    ; 60

;--------------------------------------------

L1CF7:      lda L0065              ; A5 65
            beq L1D0F              ; F0 14
            tax                    ; AA
            lda L0A24              ; AD 24 0A
            clc                    ; 18
            adc L163A,X            ; 7D 3A 16
            sta L0A24              ; 8D 24 0A

; Jump sound
	pha
	lda L0065
	ldy #20
	jsr sound
	pla

            dec L0065              ; C6 65
            bne L1D0F              ; D0 05
            and #$FC               ; 29 FC
            sta L0A24              ; 8D 24 0A
L1D0F:      rts                    ; 60

L1D10:      lda L0064              ; A5 64
            ora L0063              ; 05 63
            ora L0065              ; 05 65
            ora L004C              ; 05 4C
            bne L1D31              ; D0 17
            lda L0A2D              ; AD 2D 0A
            sta L1127              ; 8D 27 11
            lda L0A1B              ; AD 1B 0A
            sta L1128              ; 8D 28 11
            lda L0A24              ; AD 24 0A
            sta L1129              ; 8D 29 11
            lda L0055              ; A5 55
            sta L112A              ; 8D 2A 11
L1D31:      rts                    ; 60

L1D32:
            .byte $4E,$58,$3A,$54,$58,$41,$3A,$4A
            .byte $4D,$50,$74,$65,$6C,$3A,$2E,$6F
            .byte $6F,$74,$20,$52,$54,$53,$0D,$02
            .byte $6C,$06,$20,$5D,$0D,$02,$76,$06
            .byte $20,$ED,$0D,$02,$80,$0D,$20,$3F
            .byte $73,$65,$76,$65,$6E,$3D,$37,$0D
            .byte $03,$20,$1D,$20,$DB,$3A,$F1,$8A
            .byte $30,$2C,$32,$30,$29,$3B,$22,$53
            .byte $50,$52,$49,$54,$45,$53,$20,$44
            .byte $4F,$4E,$45,$22,$0D,$03,$2A,$08
            .byte $20,$41,$3D,$A5,$0D,$03,$34,$16
            .byte $20,$D0,$3D,$26,$32,$30,$30,$30
            .byte $3A,$D7,$22,$57,$49,$4C,$4C,$59
            .byte $33,$22,$0D,$FF,$1F,$00,$53,$43
            .byte $52,$00,$88,$10,$00,$00,$00,$B7
            .byte $1F,$65,$65,$64,$70,$69,$63,$00
            .byte $88,$13,$00,$00,$00,$F2,$1F,$65
            .byte $65,$64,$70,$32,$00,$88,$12,$00
            .byte $00,$00,$D0,$1F,$73,$65,$64,$78
            .byte $00,$88,$14,$00,$00,$00,$59,$20
            .byte $73,$65,$64,$79,$00,$88,$15,$00
            .byte $00,$00,$E7,$1F,$65,$6D,$32,$00
            .byte $88,$16,$00,$00,$00,$2F,$20,$65
            .byte $6D,$33,$00,$88,$17,$00,$00,$00
            .byte $39,$20,$65,$76,$65,$6E,$00,$88
            .byte $18,$00,$00,$00,$22,$00

;------------------------------------------------
; Level pointers, 75 screens
;------------------------------------------------

L1E00:
;            .byte $DC,$A0,$D1,$02,$40,$94,$DD,$1B
;            .byte $52,$7C,$BD,$E9,$31,$78,$B5,$FC
;            .byte $22,$5D,$98,$D3,$1F,$5D,$89,$D1
;            .byte $21,$5B,$9D,$E1,$25,$6C,$AB,$DC
;            .byte $21,$60,$91,$D9,$12,$58,$83,$CE
;            .byte $0B,$67,$A2,$CE,$0F,$52,$8B,$C0
;            .byte $FD,$3E,$84,$B8,$F6,$48,$89,$BD
;            .byte $FB,$18,$2F,$4E,$7E,$B0,$FD,$26
;            .byte $60,$99,$DE,$1D,$7E,$9E,$F1,$2D
;            .byte $76,$AE,$C5,$00,$00,$00,$00,$00

	.byte <L2FDC,<L1EA0,<L1ED1,<L1F02,<L1F40,<L1F94,<L1FDD,<L201B
	.byte <L2052,<L207C,<L20BD,<L20E9,<L2131,<L2178,<L21B5,<L21FC
	.byte <L2222,<L225D,<L2298,<L22D3,<L231F,<L235D,<L2389,<L23D1
	.byte <L2421,<L245B,<L249D,<L24E1,<L2525,<L256C,<L25AB,<L25DC
	.byte <L2621,<L2660,<L2691,<L26D9,<L2712,<L2758,<L2783,<L27CE
	.byte <L280B,<L2867,<L28A2,<L28CE,<L290F,<L2952,<L298B,<L29C0
	.byte <L29FD,<L2A3E,<L2A84,<L2AB8,<L2AF6,<L2B48,<L2B89,<L2BBD
	.byte <L2BFB,<L2C18,<L2C2F,<L2C4E,<L2C7E,<L2CB0,<L2CFD,<L2D26
	.byte <L2D60,<L2D99,<L2DDE,<L2E1D,<L2E7E,<L2E9E,<L2EF1,<L2F2D
	.byte <L2F76,<L2FAE,<L2FC5
	.byte $00,$00,$00,$00,$00

L1E50:
;            .byte $11,$00,$00,$01,$01,$01,$01,$02
;            .byte $02,$02,$02,$02,$03,$03,$03,$03
;            .byte $04,$04,$22,$04,$05,$05,$05,$05
;            .byte $06,$06,$06,$06,$07,$07,$07,$07
;            .byte $08,$08,$08,$08,$09,$09,$09,$09
;            .byte $0A,$0A,$0A,$0A,$0B,$0B,$0B,$0B
;            .byte $0B,$0C,$0C,$0C,$0C,$0D,$0D,$0D
;            .byte $0D,$0E,$0E,$0E,$0E,$0E,$0E,$0F
;            .byte $0F,$0F,$0F,$10,$10,$10,$10,$11
;            .byte $11,$11,$11,$00,$00,$00,$00,$00

	.byte >L2FDC,>L1EA0,>L1ED1,>L1F02,>L1F40,>L1F94,>L1FDD,>L201B
	.byte >L2052,>L207C,>L20BD,>L20E9,>L2131,>L2178,>L21B5,>L21FC
	.byte >L2222,>L225D,>L2298,>L22D3,>L231F,>L235D,>L2389,>L23D1
	.byte >L2421,>L245B,>L249D,>L24E1,>L2525,>L256C,>L25AB,>L25DC
	.byte >L2621,>L2660,>L2691,>L26D9,>L2712,>L2758,>L2783,>L27CE
	.byte >L280B,>L2867,>L28A2,>L28CE,>L290F,>L2952,>L298B,>L29C0
	.byte >L29FD,>L2A3E,>L2A84,>L2AB8,>L2AF6,>L2B48,>L2B89,>L2BBD
	.byte >L2BFB,>L2C18,>L2C2F,>L2C4E,>L2C7E,>L2CB0,>L2CFD,>L2D26
	.byte >L2D60,>L2D99,>L2DDE,>L2E1D,>L2E7E,>L2E9E,>L2EF1,>L2F2D
	.byte >L2F76,>L2FAE,>L2FC5
	.byte $00,$00,$00,$00,$00

;------------------------------------------------
; Level data, 75 screens
;------------------------------------------------

L1EA0:      .byte $40,$10,$10,$98,$FE,$0E,$76,$99
            .byte $71,$D9,$39,$EE,$C6,$20,$01,$E6
            .byte $1A,$F2,$B0,$6B,$F6,$25,$EF,$72
            .byte $1E,$A7,$3E,$BD,$0A,$E4,$FB,$21
            .byte $40,$92,$E1,$46,$4A,$36,$66,$EC
            .byte $A5,$20,$95,$8F,$36,$C1,$A7,$3F
            .byte $00

L1ED1:      .byte $40,$30,$08,$A4,$FE,$44,$77,$05
            .byte $85,$39,$84,$AC,$21,$11,$F0,$19
            .byte $08,$FB,$92,$76,$EC,$E4,$FB,$2B
            .byte $41,$50,$31,$E0,$78,$BE,$54,$22
            .byte $B1,$9E,$62,$E8,$22,$69,$11,$8F
            .byte $10,$91,$54,$4A,$51,$E1,$54,$4A
            .byte $01
L1F02:      .byte $20,$08,$00,$B0,$B4,$45,$85,$99
            .byte $85,$D9,$39,$1E,$A2,$80,$16,$C4
            .byte $82,$4C,$0E,$88,$15,$54,$BE,$C0
            .byte $83,$8F,$C4,$9A,$24,$75,$61,$98
            .byte $5B,$0F,$FA,$21,$89,$14,$C7,$16
            .byte $D0,$45,$8D,$05,$9F,$24,$FE,$7C
            .byte $90,$2B,$65,$F3,$54,$62,$4E,$A9
            .byte $9A,$63,$41,$A9,$9A,$03
L1F40:      .byte $60,$28,$04,$B7,$BA,$08,$77,$99
            .byte $85,$D9,$39,$2E,$22,$12,$17,$7E
            .byte $A7,$87,$9C,$F1,$25,$93,$78,$40
            .byte $D0,$25,$39,$44,$15,$E5,$7B,$2B
            .byte $DD,$A8,$69,$87,$05,$15,$5E,$9F
            .byte $BF,$6C,$D5,$E9,$D7,$A7,$78,$C9
            .byte $28,$7F,$45,$70,$49,$A1,$61,$23
            .byte $F2,$AB,$A6,$0B,$B7,$9F,$DA,$7E
            .byte $A1,$9B,$1B,$B1,$63,$52,$EB,$B9
            .byte $73,$51,$EB,$0B,$D7,$56,$1B,$8B
            .byte $D7,$56,$77,$00
L1F94:      .byte $10,$18,$14,$9F,$BC,$F9,$05,$F6
            .byte $45,$D8,$39,$2C,$A2,$0C,$10,$F6
            .byte $69,$41,$F3,$7B,$07,$0C,$A4,$B0
            .byte $E1,$3C,$12,$F3,$AB,$B2,$AD,$95
            .byte $24,$D0,$50,$C1,$E7,$6B,$2B,$FA
            .byte $FA,$22,$2A,$56,$50,$44,$85,$52
            .byte $2C,$D5,$70,$A5,$BF,$0A,$93,$2B
            .byte $89,$05,$F3,$E8,$22,$46,$74,$8F
            .byte $30,$77,$D4,$C5,$B1,$70,$D4,$C5
            .byte $01
L1FDD:      .byte $50,$38,$0C,$A6,$DB,$65,$A4,$EA
            .byte $25,$CC,$38,$2E,$A2,$3C,$07,$89
            .byte $C4,$E7,$5D,$23,$F1,$80,$7C,$C1
            .byte $E7,$0B,$2A,$E4,$78,$42,$98,$A1
            .byte $92,$8E,$E4,$43,$01,$56,$62,$93
            .byte $84,$90,$25,$48,$50,$61,$D0,$45
            .byte $DB,$AA,$1F,$69,$C8,$B9,$9D,$C0
            .byte $71,$63,$97,$4F,$2C,$01
L201B:      .byte $30,$04,$1C,$8E,$FE,$44,$77,$E5
            .byte $64,$39,$AC,$2E,$62,$92,$40,$0A
            .byte $82,$71,$F2,$05,$9F,$0F,$04,$12
            .byte $B6,$A6,$4D,$57,$AC,$5E,$33,$BA
            .byte $4D,$59,$88,$66,$C5,$23,$74,$41
            .byte $F7,$E3,$14,$27,$26,$52,$D3,$22
            .byte $B4,$73,$33,$2F,$B2,$6B,$00
L2052:      .byte $70,$04,$02,$A1,$FE,$14,$76,$39
            .byte $00,$D8,$15,$AD,$61,$A8,$73,$F9
            .byte $45,$E7,$CC,$C1,$F9,$B0,$1E,$07
            .byte $80,$D5,$03,$97,$B6,$5C,$DB,$71
            .byte $8B,$2E,$DE,$BB,$F8,$10,$F4,$08
            .byte $ED,$10
L207C:      .byte $48,$24,$8A,$96,$FF,$DC,$5C,$F6
            .byte $01,$D8,$35,$2E,$22,$93,$33,$C4
            .byte $59,$F2,$88,$4E,$E4,$D4,$FB,$BF
            .byte $00,$44,$0A,$20,$C4,$47,$B9,$1E
            .byte $49,$F4,$45,$B2,$DE,$62,$F5,$15
            .byte $4B,$56,$6C,$F7,$DC,$D9,$70,$21
            .byte $5D,$74,$FD,$F2,$B1,$15,$10,$8A
            .byte $29,$C6,$95,$F8,$38,$46,$95,$F8
            .byte $38
L20BD:      .byte $28,$34,$0A,$99,$F7,$0F,$76,$F7
            .byte $65,$D9,$8B,$6F,$26,$0C,$88,$02
            .byte $5C,$61,$5F,$F2,$00,$91,$53,$9A
            .byte $59,$0F,$F2,$FD,$9C,$7B,$21,$3F
            .byte $42,$0A,$81,$42,$CD,$7C,$98,$18
            .byte $04,$62,$25,$13
L20E9:      .byte $28,$0C,$1A,$9D,$7E,$65,$64,$F7
            .byte $F1,$4A,$C2,$2E,$62,$20,$B0,$96
            .byte $E0,$03,$F2,$A5,$1A,$56,$12,$59
            .byte $1A,$53,$16,$5F,$11,$5D,$19,$59
            .byte $15,$56,$13,$59,$1B,$53,$17,$5F
            .byte $93,$00,$05,$9F,$5F,$EE,$E7,$09
            .byte $12,$40,$17,$D4,$3D,$A1,$79,$32
            .byte $99,$A6,$2D,$21,$BA,$46,$53,$A4
            .byte $AB,$42,$52,$A6,$AB,$2A,$69,$02
L2131:      .byte $68,$2C,$06,$93,$3F,$4D,$4D,$F6
            .byte $45,$BC,$AD,$3D,$22,$A8,$76,$8D
            .byte $C4,$E7,$5D,$23,$F1,$25,$57,$22
            .byte $22,$27,$BF,$C6,$FF,$01,$E5,$8A
            .byte $8D,$19,$7B,$89,$40,$2E,$01,$C5
            .byte $4A,$89,$D6,$49,$82,$6F,$B2,$AF
            .byte $A4,$92,$0C,$BA,$F0,$F0,$09,$2F
            .byte $19,$CB,$19,$EF,$13,$CB,$18,$6F
            .byte $18,$DB,$B3,$92,$37,$3E,$25
L2178:      .byte $18,$2C,$16,$9B,$AB,$50,$90,$0D
            .byte $0D,$0D,$3B,$2E,$A2,$53,$06,$F1
            .byte $E1,$28,$2A,$39,$D5,$05,$F9,$F5
            .byte $01,$58,$28,$49,$12,$4B,$51,$44
            .byte $86,$A4,$92,$8D,$13,$E0,$95,$4C
            .byte $EF,$64,$AC,$40,$84,$FC,$EC,$C5
            .byte $2B,$B2,$AC,$30,$60,$C3,$72,$74
            .byte $71,$60,$BF,$07,$00
L21B5:      .byte $38,$3C,$84,$B0,$B4,$F8,$77,$99
            .byte $85,$D9,$39,$6E,$22,$31,$A1,$C4
            .byte $22,$F2,$D2,$48,$99,$98,$53,$22
            .byte $F8,$6A,$10,$A2,$EE,$2C,$58,$02
            .byte $12,$04,$12,$AD,$D6,$6F,$0D,$52
            .byte $E1,$1F,$A0,$0B,$53,$9F,$09,$28
            .byte $11,$96,$0B,$C0,$01,$94,$0B,$48
            .byte $11,$96,$0B,$C3,$C7,$94,$F3,$21
            .byte $A8,$8C,$F2,$D9,$A8,$9C,$01
L21FC:      .byte $38,$3C,$94,$18,$55,$0F,$76,$F7
            .byte $01,$D8,$39,$3E,$43,$0C,$10,$F6
            .byte $69,$41,$F3,$3B,$11,$6A,$88,$D5
            .byte $70,$BD,$F9,$0B,$1E,$61,$EE,$A1
            .byte $9F,$61,$E1,$A1,$9F,$01
L2222:      .byte $04,$22,$8E,$B0,$FE,$A0,$77,$F7
            .byte $F1,$D8,$39,$2E,$A2,$3C,$77,$D9
            .byte $D9,$97,$0B,$24,$47,$F0,$15,$A1
            .byte $C5,$C1,$05,$20,$DF,$DF,$39,$82
            .byte $48,$15,$73,$F6,$7D,$BA,$78,$86
            .byte $E1,$13,$FC,$28,$35,$27,$51,$2C
            .byte $DF,$48,$9D,$17,$17,$6A,$43,$96
            .byte $54,$6A,$8B
L225D:      .byte $04,$32,$9E,$B8,$EE,$A0,$77,$F7
            .byte $F1,$D8,$39,$2E,$A2,$0C,$10,$F6
            .byte $69,$41,$F3,$3B,$F9,$7E,$AE,$4F
            .byte $AE,$F6,$7B,$72,$89,$E6,$4B,$AA
            .byte $43,$04,$1D,$70,$84,$2E,$BE,$B8
            .byte $F1,$84,$1A,$0A,$D9,$8A,$AA,$04
            .byte $59,$12,$0B,$08,$ED,$0C,$73,$08
            .byte $ED,$4C,$27
L2298:      .byte $7E,$12,$89,$84,$3E,$F9,$05,$B4
            .byte $45,$F4,$30,$3F,$A2,$FE,$83,$20
            .byte $F3,$E8,$9C,$39,$20,$BF,$2A,$51
            .byte $5B,$01,$32,$8A,$80,$7E,$98,$F7
            .byte $82,$1F,$B8,$82,$2C,$36,$72,$A5
            .byte $A1,$2E,$63,$3B,$A6,$D0,$85,$4E
            .byte $8F,$D2,$B3,$E7,$CA,$65,$CF,$E0
            .byte $A2,$1A,$00
L22D3:      .byte $44,$0A,$99,$8C,$7E,$55,$41,$05
            .byte $01,$38,$94,$2F,$22,$B0,$43,$4A
            .byte $58,$F6,$20,$18,$27,$5F,$F0,$F9
            .byte $D8,$93,$99,$44,$70,$C5,$E2,$2B
            .byte $93,$5D,$89,$F2,$CA,$80,$C7,$B2
            .byte $CC,$57,$B4,$53,$AE,$4C,$A9,$12
            .byte $C5,$8A,$14,$4A,$9B,$3A,$65,$F2
            .byte $A4,$89,$E9,$22,$56,$A9,$8F,$59
            .byte $88,$D0,$CE,$59,$82,$D0,$AE,$58
            .byte $8E,$D0,$1E,$01
L231F:      .byte $64,$2A,$85,$92,$FE,$54,$77,$05
            .byte $01,$38,$C4,$AE,$A1,$53,$06,$31
            .byte $71,$E1,$4F,$7E,$7A,$99,$E0,$F3
            .byte $81,$9F,$33,$FC,$96,$21,$B0,$60
            .byte $41,$06,$2B,$2D,$DA,$60,$49,$86
            .byte $4C,$C2,$CA,$8C,$A6,$8B,$99,$E2
            .byte $3D,$66,$09,$41,$3B,$C5,$2D,$42
            .byte $BB,$66,$0B,$41,$7B,$02
L235D:      .byte $14,$37,$95,$DA,$FE,$D4,$77,$F7
            .byte $01,$38,$D4,$2E,$A2,$C1,$20,$6F
            .byte $03,$EF,$89,$3D,$F9,$40,$C0,$A1
            .byte $02,$0B,$A5,$8B,$8C,$99,$3D,$D6
            .byte $70,$01,$AA,$D4,$90,$03,$8A,$D2
            .byte $D2,$82,$8F,$06
L2389:      .byte $34,$1A,$D2,$1D,$3E,$0F,$76,$35
            .byte $00,$D8,$35,$2E,$82,$FF,$CB,$D1
            .byte $15,$A8,$C9,$6D,$22,$F3,$97,$A3
            .byte $80,$50,$93,$74,$45,$7A,$EF,$9D
            .byte $7A,$FD,$E7,$17,$00,$01,$E5,$0B
            .byte $34,$5F,$10,$F9,$82,$CE,$C7,$B2
            .byte $89,$5A,$7B,$F0,$EC,$1A,$64,$C4
            .byte $30,$51,$3E,$96,$49,$E3,$A7,$92
            .byte $77,$C0,$8D,$94,$89,$E2,$A7,$06
L23D1:      .byte $74,$06,$9D,$8E,$DE,$50,$04,$AC
            .byte $45,$FA,$C5,$2E,$A2,$32,$D1,$C4
            .byte $BB,$98,$4F,$7E,$40,$7D,$84,$FF
            .byte $8B,$E7,$49,$A6,$45,$27,$7B,$BC
            .byte $88,$3E,$1A,$F9,$89,$B8,$4F,$01
            .byte $21,$4E,$A2,$B4,$45,$17,$52,$81
            .byte $70,$42,$14,$19,$7A,$1D,$1B,$2B
            .byte $C5,$57,$99,$0E,$4F,$27,$4B,$53
            .byte $9A,$56,$A5,$8B,$5C,$CE,$3E,$82
            .byte $33,$F3,$82,$12,$2B,$01,$31,$07
L2421:      .byte $74,$26,$83,$91,$FE,$0E,$04,$04
            .byte $00,$C4,$B6,$2F,$22,$18,$D0,$00
            .byte $65,$81,$9E,$B0,$15,$24,$E1,$EC
            .byte $C9,$5F,$26,$28,$71,$63,$43,$22
            .byte $83,$70,$07,$64,$3E,$C5,$19,$00
            .byte $3B,$C3,$2D,$00,$BB,$C4,$03,$00
            .byte $7B,$C6,$0B,$00,$BB,$C4,$07,$00
            .byte $7B,$02
L245B:      .byte $0C,$16,$93,$99,$3E,$ED,$76,$C1
            .byte $45,$6C,$ED,$EF,$62,$84,$45,$91
            .byte $60,$01,$35,$79,$EF,$9D,$7C,$7D
            .byte $7D,$11,$F8,$6B,$42,$FA,$39,$C7
            .byte $6F,$39,$4E,$4E,$77,$5A,$BA,$85
            .byte $92,$96,$B2,$15,$0B,$46,$17,$42
            .byte $3C,$11,$0F,$97,$83,$82,$0D,$9B
            .byte $A2,$66,$30,$63,$BD,$84,$0D,$13
            .byte $A3,$06
L249D:      .byte $4C,$36,$CB,$80,$3E,$ED,$76,$C1
            .byte $45,$6C,$ED,$EF,$22,$DF,$7B,$DC
            .byte $69,$F2,$DE,$3B,$F9,$C0,$5F,$03
            .byte $D2,$CF,$39,$7E,$CB,$71,$70,$9A
            .byte $C3,$D2,$B4,$1C,$AD,$B5,$E8,$75
            .byte $C0,$90,$81,$41,$23,$4C,$99,$18
            .byte $35,$6C,$E6,$04,$83,$25,$3F,$86
            .byte $C3,$82,$CF,$87,$7D,$81,$EF,$83
            .byte $83,$83,$4F,$04
L24E1:      .byte $2C,$0E,$DB,$B0,$3E,$ED,$A0,$C5
            .byte $A0,$6C,$ED,$6F,$82,$DE,$7B,$C2
            .byte $DE,$FF,$58,$74,$C5,$E2,$93,$AF
            .byte $A9,$C9,$79,$D0,$68,$13,$F5,$C3
            .byte $B2,$2A,$5F,$15,$58,$B2,$F9,$D0
            .byte $C5,$07,$71,$7C,$80,$CA,$12,$80
            .byte $A0,$86,$E4,$10,$13,$DB,$20,$21
            .byte $0B,$82,$1E,$89,$96,$6D,$56,$C2
            .byte $6A,$E5,$34,$01
L2525:      .byte $6C,$2E,$87,$B3,$FE,$5C,$A0,$9D
            .byte $B2,$1C,$1C,$E7,$22,$B5,$73,$76
            .byte $3C,$49,$F2,$4B,$24,$9F,$65,$82
            .byte $12,$37,$36,$04,$A1,$0A,$48,$F7
            .byte $43,$96,$24,$A3,$8E,$A6,$44,$DB
            .byte $32,$1B,$4B,$23,$42,$23,$C9,$AE
            .byte $48,$A7,$8B,$A4,$76,$3D,$51,$59
            .byte $08,$BF,$54,$2D,$00,$71,$52,$47
            .byte $08,$BF,$8E,$B6,$D4,$0D,$05
L256C:      .byte $1C,$2E,$97,$9B,$FC,$80,$A1,$D1
            .byte $85,$3B,$40,$6E,$C2,$21,$01,$E6
            .byte $1A,$72,$8B,$7F,$C9,$BB,$9C,$C7
            .byte $C9,$AF,$CF,$D5,$61,$A5,$89,$2B
            .byte $93,$81,$02,$2B,$1D,$58,$B9,$E6
            .byte $D3,$BB,$57,$CF,$31,$A2,$45,$C1
            .byte $4B,$2F,$5F,$DF,$A6,$4B,$A2,$46
            .byte $5D,$7C,$08,$43,$01,$43,$05
L25AB:      .byte $BC,$20,$8F,$B7,$CB,$32,$0A,$3B
            .byte $B0,$89,$B9,$BF,$22,$0D,$48,$99
            .byte $C4,$07,$09,$8E,$CE,$99,$33,$09
            .byte $FD,$1F,$3F,$4E,$03,$06,$02,$F0
            .byte $43,$B2,$19,$2F,$05,$62,$29,$07
            .byte $91,$05,$24,$0F,$13,$D7,$00,$80
            .byte $01
L25DC:      .byte $7C,$3E,$3F,$B8,$F4,$4C,$77,$B9
            .byte $38,$41,$73,$2C,$42,$A2,$43,$8A
            .byte $E4,$F7,$DE,$7B,$EF,$BD,$F7,$DE
            .byte $8B,$CE,$99,$03,$56,$3D,$05,$F2
            .byte $12,$C4,$5B,$30,$15,$A6,$9A,$3C
            .byte $B6,$2A,$A9,$20,$B6,$10,$56,$99
            .byte $AA,$50,$45,$47,$B4,$7D,$16,$AF
            .byte $86,$8D,$93,$3A,$4B,$E1,$4A,$74
            .byte $D1,$4F,$98,$07,$00
L2621:      .byte $02,$81,$C0,$9F,$FE,$44,$77,$03
            .byte $01,$0C,$AD,$2E,$62,$21,$D1,$34
            .byte $8E,$53,$9F,$5F,$00,$24,$14,$A6
            .byte $A1,$04,$27,$A5,$39,$2D,$6D,$0D
            .byte $0A,$35,$66,$0F,$2E,$DC,$78,$81
            .byte $35,$96,$40,$17,$DE,$3C,$E1,$50
            .byte $40,$37,$73,$44,$40,$B7,$76,$54
            .byte $40,$97,$76,$F2,$41,$37,$05
L2660:      .byte $42,$91,$30,$84,$D4,$0E,$76,$89
            .byte $C9,$89,$A9,$3D,$A2,$FE,$73,$25
            .byte $6B,$92,$4F,$6C,$40,$7D,$BE,$1F
            .byte $12,$C4,$1C,$5A,$1A,$59,$96,$E8
            .byte $D7,$14,$E0,$C7,$61,$8C,$8B,$1E
            .byte $71,$90,$B1,$9D,$11,$89,$A0,$3A
            .byte $03
L2691:      .byte $42,$B1,$48,$94,$D4,$28,$76,$89
            .byte $89,$89,$A9,$3F,$22,$84,$BD,$FF
            .byte $E1,$08,$84,$4D,$27,$79,$BA,$94
            .byte $7C,$20,$BF,$2A,$C7,$FF,$01,$A1
            .byte $15,$91,$02,$8D,$A9,$C8,$4A,$A9
            .byte $C5,$75,$EB,$25,$4B,$3D,$7A,$F2
            .byte $EC,$C5,$AB,$5B,$85,$60,$12,$CB
            .byte $66,$72,$D2,$45,$BE,$45,$1F,$91
            .byte $2E,$ED,$95,$A2,$1C,$59,$56,$01
L26D9:      .byte $22,$89,$58,$9C,$3A,$0F,$76,$C9
            .byte $B1,$88,$49,$4E,$A1,$2C,$48,$59
            .byte $90,$74,$86,$D6,$10,$CC,$17,$7C
            .byte $BE,$96,$3F,$36,$87,$2D,$FE,$C9
            .byte $F9,$AE,$CB,$A8,$E2,$48,$50,$89
            .byte $17,$75,$5C,$7B,$AC,$88,$15,$43
            .byte $E9,$32,$84,$66,$2D,$06,$C6,$7C
            .byte $0A
L2712:      .byte $62,$99,$44,$92,$AA,$28,$76,$A9
            .byte $C8,$89,$49,$4E,$C1,$12,$69,$24
            .byte $3E,$62,$73,$04,$16,$91,$13,$32
            .byte $2C,$F3,$CB,$04,$19,$33,$8E,$53
            .byte $A6,$B1,$DD,$CB,$B2,$FC,$59,$3F
            .byte $FB,$AA,$80,$0F,$CB,$D0,$32,$08
            .byte $1E,$3E,$F6,$E2,$65,$1C,$3A,$72
            .byte $BC,$A5,$0B,$18,$1F,$89,$62,$F9
            .byte $34,$33,$27,$90,$4D,$02
L2758:      .byte $52,$A9,$40,$96,$FE,$0A,$77,$3B
            .byte $64,$F3,$88,$2F,$62,$0C,$61,$E0
            .byte $71,$A1,$F5,$11,$78,$7D,$7E,$19
            .byte $C8,$B4,$59,$80,$43,$D2,$2E,$60
            .byte $91,$87,$D2,$05,$14,$0F,$D3,$EB
            .byte $F7,$C9,$01
L2783:      .byte $12,$99,$54,$9E,$DE,$E0,$76,$F7
            .byte $71,$F1,$3B,$AE,$A2,$B8,$D3,$F9
            .byte $45,$07,$F0,$29,$2B,$18,$C4,$61
            .byte $6A,$C8,$AF,$F7,$52,$B6,$83,$53
            .byte $8D,$14,$2F,$F8,$CA,$D5,$CB,$93
            .byte $0A,$79,$26,$04,$05,$08,$2B,$C2
            .byte $FC,$B7,$F2,$62,$6F,$78,$31,$DB
            .byte $89,$29,$46,$8C,$17,$5A,$98,$5C
            .byte $A2,$97,$21,$22,$24,$C8,$81,$2E
            .byte $10,$7E,$00
L27CE:      .byte $72,$B9,$4C,$BE,$3E,$09,$77,$4D
            .byte $F1,$2C,$89,$2F,$22,$B1,$6B,$36
            .byte $65,$20,$62,$3A,$03,$7D,$08,$CF
            .byte $C3,$FA,$68,$D9,$07,$94,$8F,$B0
            .byte $D2,$74,$20,$9F,$E8,$E3,$C9,$5E
            .byte $C9,$F1,$51,$68,$38,$4E,$A7,$12
            .byte $8B,$78,$44,$8E,$A6,$1B,$E9,$46
            .byte $84,$6C,$BD,$F1,$08
L280B:      .byte $61,$A5,$42,$11,$D8,$62,$76,$F7
            .byte $65,$0D,$3D,$2F,$A2,$72,$14,$FE
            .byte $A5,$26,$32,$E2,$27,$BF,$C6,$FF
            .byte $01,$C5,$40,$98,$59,$52,$CB,$92
            .byte $72,$D6,$06,$14,$24,$30,$51,$3E
            .byte $BA,$F4,$FC,$FA,$1B,$22,$AE,$21
            .byte $18,$3E,$02,$A3,$C7,$60,$FC,$04
            .byte $4C,$9E,$82,$E9,$33,$30,$FB,$0C
            .byte $5D,$80,$F5,$0C,$C2,$8C,$CD,$94
            .byte $E2,$83,$CD,$CA,$D6,$8C,$CC,$DA
            .byte $F4,$04,$CD,$0C,$CC,$83,$4D,$91
            .byte $ED,$8C,$CD,$1A
L2867:      .byte $0A,$95,$D2,$B8,$EC,$0E,$76,$7D
            .byte $84,$BD,$85,$2E,$22,$9A,$D0,$7A
            .byte $EC,$F4,$B4,$73,$CA,$95,$7C,$6A
            .byte $4A,$43,$0E,$0A,$3E,$5F,$1A,$F9
            .byte $95,$38,$54,$38,$F9,$60,$15,$3A
            .byte $4C,$09,$1E,$2A,$6C,$78,$CC,$E8
            .byte $14,$6E,$CA,$C4,$12,$6E,$C6,$F4
            .byte $16,$6E,$0E
L28A2:      .byte $4A,$B5,$CA,$94,$F4,$0E,$76,$7D
            .byte $00,$BC,$85,$2E,$22,$93,$1A,$0F
            .byte $EA,$42,$9E,$17,$56,$1D,$C1,$E7
            .byte $63,$C1,$E4,$FB,$33,$00,$2C,$4A
            .byte $F0,$10,$EC,$87,$D4,$87,$F0,$12
            .byte $F0,$D5,$1D,$00
L28CE:      .byte $2A,$8D,$DA,$BC,$FC,$10,$76,$7D
            .byte $B8,$BC,$85,$2E,$22,$BC,$CB,$79
            .byte $3C,$EF,$F2,$F3,$1A,$D8,$7C,$04
            .byte $1F,$3F,$09,$E6,$AF,$20,$CB,$82
            .byte $3F,$E8,$AF,$B9,$0C,$B2,$D6,$46
            .byte $6C,$3B,$36,$A4,$4B,$A1,$4C,$31
            .byte $7E,$48,$C5,$82,$89,$D1,$65,$30
            .byte $5D,$40,$F8,$10,$9E,$99,$17,$D2
            .byte $16
L290F:      .byte $6A,$AD,$C6,$B2,$BE,$62,$76,$F7
            .byte $85,$0D,$A3,$6F,$26,$A2,$60,$2E
            .byte $3E,$E3,$62,$16,$E9,$80,$7C,$B9
            .byte $45,$EB,$34,$C9,$6A,$99,$50,$F0
            .byte $F3,$57,$C0,$83,$2A,$AF,$70,$7E
            .byte $89,$EB,$F8,$C2,$0D,$BA,$28,$64
            .byte $C8,$93,$48,$15,$00,$E0,$A8,$16
            .byte $00,$60,$D3,$30,$16,$73,$33,$27
            .byte $96,$31,$00
L2952:      .byte $1A,$9D,$D6,$BA,$F6,$28,$E2,$88
            .byte $E3,$CD,$62,$3D,$62,$50,$1C,$3E
            .byte $9F,$2A,$C1,$E7,$CD,$67,$3F,$67
            .byte $03,$3F,$04,$0B,$2B,$F8,$C8,$8A
            .byte $E3,$A4,$39,$BC,$BB,$B2,$4A,$3A
            .byte $59,$6C,$2C,$99,$2E,$B8,$7B,$64
            .byte $87,$42,$76,$AD,$BC,$6D,$5F,$A9
            .byte $09
L298B:      .byte $5A,$BD,$4E,$17,$3E,$0F,$76,$F7
            .byte $01,$12,$93,$6E,$22,$30,$41,$C0
            .byte $8B,$0C,$22,$39,$A1,$C3,$71,$24
            .byte $4F,$D5,$E9,$3C,$0B,$F3,$55,$17
            .byte $3B,$69,$53,$81,$CE,$6A,$8C,$56
            .byte $43,$F4,$9A,$F0,$C8,$F7,$8C,$C5
            .byte $39,$50,$81,$C4,$11
L29C0:      .byte $BA,$A8,$5E,$9F,$FE,$32,$D2,$F7
            .byte $01,$8C,$D2,$2E,$22,$8D,$B3,$64
            .byte $3C,$08,$58,$3A,$09,$73,$30,$DF
            .byte $67,$F9,$F5,$13,$66,$48,$0F,$50
            .byte $B1,$C4,$CA,$3C,$1E,$78,$A8,$DA
            .byte $45,$D5,$0E,$AA,$B6,$51,$B5,$85
            .byte $AA,$C9,$42,$55,$2A,$D3,$D8,$87
            .byte $60,$14,$62,$D6,$00
L29FD:      .byte $06,$43,$D4,$10,$3E,$ED,$76,$35
            .byte $00,$D8,$35,$AC,$22,$B8,$60,$BC
            .byte $81,$71,$B3,$7B,$9C,$68,$7D,$EA
            .byte $65,$9F,$5F,$10,$00,$04,$94,$2F
            .byte $D0,$7C,$41,$E4,$0B,$3A,$5F,$38
            .byte $A1,$AB,$D0,$90,$3D,$BE,$0C,$13
            .byte $25,$5D,$80,$F8,$58,$21,$8A,$9F
            .byte $52,$B9,$41,$2E,$4A,$41,$8D,$8E
            .byte $1A
L2A3E:      .byte $46,$93,$D2,$98,$36,$C3,$C3,$F7
            .byte $43,$0C,$C3,$3E,$42,$9A,$B3,$0C
            .byte $EC,$F4,$92,$17,$5A,$03,$46,$5E
            .byte $8E,$60,$9C,$FA,$82,$FC,$E2,$75
            .byte $66,$DC,$94,$68,$51,$A1,$C3,$56
            .byte $2E,$20,$C1,$0F,$7F,$70,$0C,$7E
            .byte $64,$32,$7E,$68,$06,$7E,$F8,$83
            .byte $21,$74,$21,$FF,$A3,$84,$01,$E0
            .byte $EB,$44,$29,$A0,$71,$00
L2A84:      .byte $46,$B3,$CA,$14,$FF,$0E,$82,$F6
            .byte $83,$0D,$AD,$2C,$A2,$9A,$D0,$7A
            .byte $EC,$F4,$A0,$88,$F8,$41,$90,$F9
            .byte $19,$CA,$A5,$05,$99,$A5,$05,$F3
            .byte $99,$C8,$29,$03,$2C,$73,$36,$9C
            .byte $78,$F0,$23,$38,$04,$F8,$28,$59
            .byte $14,$EF,$6A,$00
L2AB8:      .byte $26,$8B,$DA,$9C,$CE,$32,$02,$02
            .byte $7D,$B5,$FD,$2F,$22,$12,$21,$78
            .byte $3C,$EE,$34,$39,$43,$38,$7B,$0E
            .byte $E5,$4B,$BE,$2A,$C3,$5D,$F5,$2E
            .byte $CB,$04,$2A,$FC,$D8,$04,$FC,$20
            .byte $96,$51,$04,$59,$08,$4E,$17,$B8
            .byte $3D,$96,$22,$FB,$A1,$02,$9F,$33
            .byte $B3,$80,$9D,$4B,$8F,$06
L2AF6:      .byte $66,$AB,$C6,$92,$F7,$22,$22,$F6
            .byte $45,$A2,$A2,$2C,$A2,$FF,$9B,$CE
            .byte $9D,$FC,$FA,$05,$85,$60,$9D,$32
            .byte $67,$C9,$4C,$85,$D3,$E4,$29,$73
            .byte $D3,$B0,$51,$E3,$26,$1D,$BB,$0C
            .byte $1C,$34,$78,$C8,$CD,$CC,$59,$B3
            .byte $E7,$AC,$5C,$B3,$73,$D7,$EE,$3D
            .byte $C9,$0A,$2F,$57,$B5,$82,$F4,$F0
            .byte $FE,$2D,$BA,$60,$EC,$31,$0C,$08
            .byte $0C,$15,$1D,$05,$D8,$28,$AD,$00
            .byte $98,$39
L2B48:      .byte $16,$AB,$D6,$86,$FC,$F2,$0B,$C4
            .byte $F0,$F2,$C8,$2E,$A2,$BC,$C8,$8F
            .byte $11,$10,$9F,$B3,$A7,$BE,$66,$68
            .byte $2B,$33,$DE,$14,$69,$12,$C8,$AF
            .byte $C6,$42,$09,$D3,$4B,$A4,$8F,$92
            .byte $7C,$96,$E9,$8A,$3C,$B2,$F8,$B2
            .byte $32,$90,$69,$15,$5D,$84,$3E,$FD
            .byte $91,$14,$34,$2C,$55,$C0,$17,$DB
            .byte $38
L2B89:      .byte $36,$BB,$D5,$B6,$EC,$F2,$77,$C1
            .byte $B9,$80,$64,$EF,$22,$84,$7D,$79
            .byte $47,$90,$1F,$77,$9A,$9C,$7C,$1B
            .byte $7E,$63,$00,$08,$0C,$8C,$07,$7F
            .byte $0F,$7B,$58,$5F,$1D,$92,$EF,$8F
            .byte $54,$C1,$57,$05,$62,$71,$C4,$D0
            .byte $85,$92,$0F,$00
L2BBD:      .byte $36,$BB,$DD,$B1,$FE,$F2,$65,$F7
            .byte $F1,$80,$3A,$2E,$22,$B0,$6B,$F6
            .byte $E5,$FD,$BC,$C8,$07,$24,$D9,$21
            .byte $DF,$2E,$B1,$37,$02,$22,$AA,$03
            .byte $60,$56,$79,$6E,$51,$56,$21,$11
            .byte $FC,$AC,$99,$1B,$F3,$91,$2E,$6C
            .byte $7B,$EC,$0E,$A5,$76,$E9,$8D,$E5
            .byte $03,$ED,$F1,$E5,$43,$0D
L2BFB:      .byte $4E,$A7,$D3,$99,$DE,$0E,$76,$F7
            .byte $01,$88,$B7,$2F,$22,$1A,$C8,$24
            .byte $BE,$54,$BC,$D7,$E3,$0C,$7F,$0B
            .byte $4C,$AF,$F9,$FF,$00
L2C18:      .byte $2E,$97,$2B,$99,$DE,$0E,$76,$F7
            .byte $01,$88,$B7,$2F,$62,$1A,$D1,$FA
            .byte $0C,$7F,$0B,$CC,$FF,$07,$00
L2C2F:      .byte $2E,$97,$CB,$95,$CA,$0E,$A8,$F7
            .byte $01,$88,$B7,$3D,$C2,$B1,$B0,$4A
            .byte $58,$F6,$2A,$C8,$24,$9E,$E1,$EF
            .byte $87,$29,$4F,$CC,$18,$F1,$00
L2C4E:      .byte $54,$37,$CD,$9D,$FE,$0E,$D8,$F6
            .byte $45,$D8,$39,$2E,$A2,$13,$2F,$39
            .byte $6B,$F2,$20,$18,$07,$E4,$FB,$26
            .byte $E7,$A2,$53,$F2,$61,$FD,$13,$FB
            .byte $CC,$B9,$32,$6D,$E6,$7C,$4A,$38
            .byte $00,$30,$0B,$78,$A3,$DF,$6A,$00
L2C7E:      .byte $41,$BF,$C7,$B3,$FE,$0E,$76,$F7
            .byte $A1,$98,$A2,$67,$A2,$0C,$40,$20
            .byte $3A,$2B,$5E,$26,$F8,$80,$7C,$7F
            .byte $65,$F9,$35,$56,$A4,$11,$07,$DD
            .byte $76,$2B,$00,$0E,$14,$C1,$0F,$DC
            .byte $47,$28,$36,$54,$54,$08,$0E,$54
            .byte $54,$00
L2CB0:      .byte $BE,$88,$DF,$BB,$3E,$09,$77,$35
            .byte $85,$0D,$95,$2F,$22,$60,$C9,$9A
            .byte $C4,$9D,$9E,$07,$36,$C7,$71,$E6
            .byte $A3,$E0,$63,$4D,$9F,$EF,$AF,$9C
            .byte $EA,$EF,$80,$30,$F8,$AD,$80,$D0
            .byte $12,$B7,$94,$E3,$08,$99,$64,$80
            .byte $A5,$43,$47,$8E,$D1,$75,$D9,$BA
            .byte $6D,$FB,$8E,$9D,$BB,$76,$EF,$C7
            .byte $DE,$CC,$34,$55,$9E,$4D,$91,$D4
            .byte $1E,$37,$36,$94,$00
L2CFD:      .byte $21,$AF,$CF,$B7,$3E,$0F,$76,$F7
            .byte $85,$8D,$EC,$2F,$62,$0C,$61,$20
            .byte $3A,$7B,$E6,$A3,$FF,$13,$81,$A0
            .byte $F2,$05,$7E,$E8,$31,$C9,$18,$3C
            .byte $34,$19,$86,$3F,$A5,$13,$2C,$44
            .byte $39
L2D26:      .byte $1E,$92,$C0,$9B,$FE,$10,$76,$F7
            .byte $01,$98,$A2,$2F,$A2,$70,$31,$F0
            .byte $35,$20,$32,$89,$07,$C4,$19,$21
            .byte $5F,$A0,$C1,$5A,$4D,$F2,$69,$AE
            .byte $7F,$72,$04,$95,$0F,$4B,$FC,$5F
            .byte $4B,$17,$9F,$5D,$7B,$1C,$86,$B0
            .byte $49,$89,$F5,$12,$66,$8E,$F1,$12
            .byte $66,$0E
L2D60:      .byte $B1,$44,$20,$80,$BC,$11,$E0,$60
            .byte $84,$61,$E1,$2D,$62,$19,$88,$98
            .byte $D8,$83,$F3,$03,$E0,$3A,$06,$01
            .byte $06,$22,$60,$14,$68,$30,$A2,$07
            .byte $66,$20,$59,$C6,$24,$C8,$50,$24
            .byte $B0,$39,$79,$CA,$B2,$ED,$27,$46
            .byte $96,$F4,$A9,$93,$26,$5D,$A0,$F5
            .byte $00
L2D99:      .byte $3C,$0F,$3F,$98,$FC,$08,$89,$04
            .byte $21,$B5,$30,$2D,$22,$28,$D0,$DA
            .byte $95,$FC,$12,$27,$3A,$93,$78,$F2
            .byte $65,$56,$12,$33,$96,$4D,$32,$99
            .byte $33,$CB,$E4,$7E,$1A,$A7,$1C,$07
            .byte $AB,$0E,$23,$3A,$8E,$EC,$34,$2A
            .byte $59,$D2,$5A,$74,$3A,$5D,$D6,$56
            .byte $CC,$57,$A8,$47,$B2,$0F,$93,$91
            .byte $96,$6F,$66,$67,$00
L2DDE:      .byte $21,$9F,$24,$DC,$BD,$4D,$4D,$24
            .byte $65,$61,$09,$2C,$22,$C8,$D7,$F7
            .byte $3F,$00,$22,$AE,$20,$AA,$33,$F0
            .byte $FD,$30,$0B,$FD,$32,$D3,$81,$48
            .byte $42,$24,$1E,$2A,$A8,$70,$09,$86
            .byte $91,$55,$FE,$42,$EC,$95,$99,$B0
            .byte $C7,$1B,$A7,$E8,$32,$15,$E6,$A2
            .byte $26,$3F,$54,$E2,$84,$AF,$04
L2E1D:      .byte $61,$45,$28,$9C,$2B,$4D,$65,$D4
            .byte $B0,$12,$35,$3C,$22,$FE,$6B,$C2
            .byte $92,$87,$88,$D6,$20,$9E,$81,$3F
            .byte $58,$86,$61,$BE,$5F,$E7,$BE,$FB
            .byte $E7,$6C,$55,$B6,$DB,$73,$45,$3E
            .byte $B8,$C2,$64,$15,$50,$12,$06,$FC
            .byte $92,$6C,$F1,$2C,$57,$A5,$0A,$36
            .byte $64,$D5,$97,$29,$EF,$C6,$BD,$18
            .byte $21,$CB,$9E,$0D,$67,$6E,$4F,$57
            .byte $91,$12,$22,$71,$E2,$E8,$E9,$27
            .byte $5E,$65,$74,$90,$9E,$32,$72,$50
            .byte $5E,$4A,$74,$D0,$5A,$58,$DE,$91
            .byte $00
L2E7E:      .byte $DE,$08,$29,$BA,$DC,$C3,$A5,$24
            .byte $B1,$89,$89,$03,$2E,$FF,$A3,$D1
            .byte $D9,$FC,$B0,$73,$F1,$C0,$81,$78
            .byte $51,$50,$D1,$74,$41,$F7,$03,$00
L2E9E:      .byte $FA,$58,$C4,$B0,$34,$A5,$A5,$E4
            .byte $DA,$71,$F2,$1E,$C1,$FF,$4B,$04
            .byte $95,$28,$F2,$78,$AC,$80,$88,$4F
            .byte $A0,$0C,$F2,$E6,$A3,$DF,$E6,$E8
            .byte $2C,$B6,$DB,$14,$36,$5A,$B1,$CE
            .byte $8A,$D5,$36,$92,$43,$05,$5F,$35
            .byte $C8,$C2,$BE,$2F,$FC,$13,$40,$EA
            .byte $D1,$3A,$4F,$F7,$7B,$16,$F6,$51
            .byte $FE,$93,$C4,$34,$B3,$D3,$C4,$07
            .byte $B5,$AB,$24,$39,$B3,$E7,$64,$34
            .byte $B3,$4B,$00
L2EF1:      .byte $D1,$40,$2C,$3E,$FC,$A4,$A5,$8C
            .byte $B1,$F5,$1C,$67,$62,$FE,$C3,$51
            .byte $54,$72,$06,$59,$F9,$07,$F2,$41
            .byte $86,$15,$A2,$04,$1E,$44,$04,$32
            .byte $90,$07,$03,$16,$50,$E0,$D3,$C8
            .byte $AF,$FE,$6A,$B8,$76,$78,$48,$38
            .byte $95,$7B,$2A,$98,$27,$7B,$28,$38
            .byte $2B,$F8,$48,$00
L2F2D:      .byte $F1,$78,$2C,$AE,$2D,$33,$50,$3D
            .byte $B9,$FC,$9D,$1E,$22,$8B,$C5,$24
            .byte $DE,$FF,$70,$14,$95,$9C,$81,$5F
            .byte $F3,$81,$A8,$7C,$C7,$CF,$EA,$F9
            .byte $35,$2F,$E6,$A4,$1F,$EA,$81,$C1
            .byte $E3,$D7,$62,$95,$AC,$D9,$A6,$CF
            .byte $A3,$27,$D8,$AF,$49,$64,$39,$62
            .byte $C3,$85,$C5,$1E,$93,$AE,$CD,$45
            .byte $2A,$2D,$EA,$93,$33,$49,$80,$58
            .byte $01
L2F76:      .byte $81,$44,$22,$81,$DB,$08,$31,$02
            .byte $71,$0D,$3D,$2E,$22,$FF,$73,$94
            .byte $3E,$2D,$10,$B1,$88,$1C,$BD,$C4
            .byte $D4,$E4,$17,$94,$64,$5D,$00,$F9
            .byte $01,$D8,$67,$C9,$64,$C1,$25,$75
            .byte $75,$F2,$63,$9C,$2B,$B0,$4B,$51
            .byte $39,$B4,$A7,$F0,$78,$7E,$6A,$00
L2FAE:      .byte $C9,$A4,$33,$95,$DE,$0E,$76,$F7
            .byte $01,$88,$B7,$2F,$62,$1A,$D1,$FA
            .byte $0C,$7F,$0B,$CC,$FF,$07,$00
L2FC5:      .byte $A9,$54,$D2,$95,$DE,$0E,$76,$F7
            .byte $01,$88,$B7,$2F,$62,$1A,$D1,$FA
            .byte $0C,$7F,$0B,$CC,$FF,$07,$00
L2FDC:      .byte $86,$FC,$79,$3F,$84,$FC,$00,$00
            .byte $06,$3D,$00,$A0,$02,$00,$00,$00
            .byte $00,$01,$00,$00,$00,$00,$00,$0F
            .byte $0F,$0F,$0D,$0F,$0F,$06,$0F,$00
            .byte $00,$00,$00,$00

;------------------------------------------------
; Sprite data
;------------------------------------------------

L3000:
            .byte $3C,$76,$43,$8D,$80,$02,$80,$01
            .byte $84,$09,$88,$35,$48,$42,$20,$80
            .byte $20,$80,$10,$80,$10,$80,$10,$80
            .byte $10,$80,$10,$80,$10,$80,$10,$80

            .byte $37,$EC,$77,$EE,$00,$00,$6D,$76
            .byte $EE,$F7,$ED,$77,$DF,$FB,$D5,$5B
            .byte $DB,$BB,$D5,$5B,$EF,$F7,$EF,$F7
            .byte $6F,$F6,$00,$00,$77,$EE,$37,$EC

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$80,$05,$00,$1A,$80
            .byte $75,$40,$BB,$80,$6F,$40,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$03,$C0,$37,$E0
            .byte $5D,$70,$36,$A0,$01,$50,$02,$80
            .byte $01,$40,$00,$A0,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$08,$00,$50,$19,$A8
            .byte $2F,$54,$19,$B8,$00,$F4,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$0A
            .byte $00,$14,$00,$28,$00,$14,$03,$6A
            .byte $05,$D7,$03,$7E,$00,$3D,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$50,$00
            .byte $28,$00,$14,$00,$28,$00,$56,$C0
            .byte $EB,$A0,$7E,$C0,$BC,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$10,$00,$0A,$00,$15,$98
            .byte $2A,$F4,$1D,$98,$2F,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$03,$C0,$07,$EC
            .byte $0E,$BA,$05,$6C,$0A,$80,$01,$40
            .byte $02,$80,$05,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$01,$00,$00,$A0,$01,$58
            .byte $02,$AE,$01,$DD,$02,$F6,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $2D,$00,$08,$00,$B3,$40,$33,$00
            .byte $C0,$C0,$52,$80,$00,$00,$FF,$C0
            .byte $16,$00,$16,$00,$16,$00,$16,$00
            .byte $16,$00,$16,$00,$16,$00,$16,$00

            .byte $0D,$20,$28,$00,$0C,$F0,$0C,$D0
            .byte $24,$00,$0D,$20,$00,$00,$3F,$F0
            .byte $05,$80,$05,$80,$05,$80,$05,$80
            .byte $05,$80,$05,$80,$05,$80,$05,$80

            .byte $05,$28,$0C,$0C,$03,$30,$0B,$34
            .byte $00,$40,$02,$D0,$00,$00,$0F,$FC
            .byte $01,$60,$01,$60,$01,$60,$01,$60
            .byte $01,$60,$01,$60,$01,$60,$01,$60

            .byte $01,$2C,$00,$09,$02,$CC,$03,$CC
            .byte $00,$05,$01,$2C,$00,$00,$03,$FF
            .byte $00,$58,$00,$58,$00,$58,$00,$58
            .byte $00,$58,$00,$58,$00,$58,$00,$58

            .byte $16,$00,$16,$00,$16,$00,$16,$00
            .byte $16,$00,$16,$00,$16,$00,$16,$40
            .byte $17,$C0,$17,$C0,$0B,$C0,$0B,$C0
            .byte $05,$C0,$02,$40,$01,$80,$00,$40

            .byte $05,$80,$05,$80,$05,$80,$05,$80
            .byte $05,$80,$05,$80,$05,$80,$05,$80
            .byte $07,$80,$0F,$C0,$08,$40,$13,$20
            .byte $13,$20,$08,$40,$0F,$C0,$03,$00

            .byte $01,$60,$01,$60,$01,$60,$01,$60
            .byte $01,$60,$01,$60,$01,$60,$09,$60
            .byte $0F,$E0,$0B,$E0,$0B,$C0,$0B,$C0
            .byte $0B,$80,$0B,$00,$0E,$00,$08,$00

            .byte $00,$58,$00,$58,$00,$58,$00,$58
            .byte $00,$58,$00,$58,$00,$58,$00,$58
            .byte $00,$58,$00,$BC,$00,$BC,$01,$7E
            .byte $01,$7E,$00,$BC,$00,$DC,$00,$30

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $FF,$FF,$C5,$7B,$DD,$7B,$DD,$3B
            .byte $DD,$7B,$DD,$7B,$DD,$11,$FF,$FF

            .byte $C0,$03,$E0,$07,$A3,$C5,$E7,$E7
            .byte $AC,$35,$E8,$17,$AB,$D5,$FF,$FF
            .byte $BF,$FD,$6F,$F6,$09,$90,$09,$90
            .byte $09,$90,$0F,$F0,$0F,$F0,$07,$E0

            .byte $00,$00,$00,$00,$03,$C0,$07,$E0
            .byte $0C,$30,$C8,$13,$AB,$D5,$FF,$FF
            .byte $BE,$FD,$EF,$F7,$A9,$95,$A9,$95
            .byte $A9,$95,$AF,$F5,$AF,$F5,$C7,$E3

            .byte $07,$C0,$0F,$A0,$1F,$50,$3E,$88
            .byte $3F,$08,$3E,$88,$3F,$08,$1E,$90
            .byte $1F,$70,$0F,$A0,$07,$C0,$07,$C0
            .byte $03,$80,$03,$80,$01,$00,$01,$00

            .byte $18,$00,$6E,$00,$5E,$00,$BF,$00
            .byte $B7,$00,$5E,$00,$6E,$00,$18,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$06,$00,$1B,$80,$17,$80
            .byte $2F,$C0,$2B,$C0,$17,$80,$1B,$80
            .byte $06,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $01,$80,$06,$E0,$05,$E0,$0B,$F0
            .byte $0A,$F0,$05,$E0,$06,$E0,$01,$80

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$60,$01,$B8,$01,$78
            .byte $02,$FC,$02,$BC,$01,$78,$01,$B8
            .byte $00,$60,$00,$00,$00,$00,$00,$00

            .byte $07,$E0,$1B,$F8,$61,$9E,$FF,$FF
            .byte $02,$BC,$01,$78,$18,$B0,$25,$58
            .byte $42,$AC,$82,$AC,$85,$56,$85,$56
            .byte $4A,$AB,$3F,$FF,$00,$00,$00,$00

            .byte $00,$00,$07,$E0,$1B,$F8,$61,$9E
            .byte $FF,$FF,$0A,$F0,$05,$E0,$02,$C0
            .byte $05,$60,$0A,$B0,$0A,$B0,$15,$58
            .byte $15,$58,$2A,$AC,$3F,$FC,$00,$00

            .byte $00,$00,$00,$00,$07,$E0,$1B,$F8
            .byte $61,$9E,$FF,$FF,$2B,$C0,$17,$80
            .byte $0B,$18,$15,$A4,$2A,$C2,$2A,$C1
            .byte $55,$61,$55,$61,$AA,$B2,$FF,$FC

            .byte $00,$00,$07,$E0,$1B,$F8,$61,$9E
            .byte $FF,$FF,$0A,$F0,$05,$E0,$02,$C0
            .byte $04,$E0,$0A,$B0,$0A,$B0,$14,$D8
            .byte $14,$D8,$2A,$AC,$3F,$FC,$00,$00

            .byte $00,$40,$40,$58,$58,$50,$50,$50
            .byte $50,$50,$50,$F0,$7F,$50,$6A,$B0
            .byte $3A,$A8,$35,$58,$15,$78,$0A,$CC
            .byte $05,$4C,$03,$8A,$00,$0C,$00,$00

            .byte $04,$20,$02,$40,$02,$40,$02,$40
            .byte $03,$70,$03,$E0,$05,$60,$0A,$B0
            .byte $0A,$B0,$05,$60,$03,$C0,$01,$80
            .byte $01,$80,$02,$80,$01,$80,$00,$00

            .byte $02,$00,$1A,$02,$0A,$1A,$0A,$0A
            .byte $0A,$0A,$0F,$0A,$0D,$FE,$1A,$AA
            .byte $1A,$AC,$15,$54,$1F,$58,$32,$B0
            .byte $33,$A0,$51,$C0,$30,$00,$00,$00

            .byte $04,$20,$02,$40,$02,$40,$02,$40
            .byte $03,$70,$03,$E0,$07,$60,$0E,$B0
            .byte $0E,$B0,$05,$60,$03,$60,$02,$C0
            .byte $01,$C0,$00,$E0,$00,$C0,$00,$00

            .byte $04,$20,$04,$20,$02,$40,$02,$40
            .byte $01,$80,$02,$40,$05,$A0,$0F,$D0
            .byte $15,$A8,$2A,$54,$2C,$34,$58,$1A
            .byte $50,$0A,$B0,$0D,$A0,$05,$C0,$03

            .byte $00,$00,$04,$20,$04,$20,$02,$40
            .byte $02,$40,$01,$80,$02,$40,$0D,$B0
            .byte $37,$EC,$5C,$3A,$B0,$0D,$C0,$03
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$04,$20,$04,$20
            .byte $02,$40,$01,$80,$3E,$7C,$DD,$BB
            .byte $FF,$FF,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$04,$20,$04,$20,$02,$40
            .byte $02,$40,$01,$80,$02,$40,$0D,$B0
            .byte $37,$EC,$5C,$3A,$B0,$0D,$C0,$03
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $01,$E0,$03,$30,$03,$F0,$C3,$30
            .byte $A2,$13,$92,$17,$AF,$3F,$B1,$E3
            .byte $A9,$FB,$AF,$3B,$92,$15,$A2,$13
            .byte $C3,$30,$03,$F0,$03,$30,$01,$E0

            .byte $01,$E0,$03,$F0,$03,$30,$C2,$10
            .byte $A2,$13,$93,$37,$AF,$FF,$B1,$E3
            .byte $A9,$3B,$AE,$1B,$92,$15,$A3,$33
            .byte $C3,$F0,$02,$10,$03,$30,$01,$E0

            .byte $01,$E0,$03,$30,$02,$10,$C2,$10
            .byte $A3,$33,$93,$F7,$AF,$3F,$B2,$13
            .byte $AA,$1B,$AF,$3B,$93,$F5,$A3,$33
            .byte $C2,$10,$02,$10,$03,$30,$01,$E0

            .byte $01,$E0,$03,$30,$02,$10,$C3,$F0
            .byte $A3,$33,$92,$17,$AE,$1F,$B3,$33
            .byte $AD,$FB,$AD,$FB,$93,$35,$A2,$13
            .byte $C2,$10,$03,$30,$03,$F0,$01,$E0

            .byte $10,$00,$20,$00,$10,$20,$08,$50
            .byte $0C,$40,$0F,$80,$17,$00,$3A,$00
            .byte $7C,$00,$7C,$00,$3F,$00,$09,$80
            .byte $1C,$80,$3E,$40,$34,$60,$18,$00

            .byte $02,$00,$05,$00,$04,$00,$04,$10
            .byte $0C,$28,$0F,$C0,$0B,$80,$1D,$00
            .byte $3E,$00,$3E,$00,$1F,$80,$04,$C0
            .byte $0E,$40,$1F,$60,$1A,$60,$0C,$00

            .byte $00,$00,$00,$40,$00,$A0,$03,$00
            .byte $07,$00,$07,$FC,$05,$C2,$0E,$82
            .byte $1F,$00,$1F,$00,$0F,$C0,$04,$C0
            .byte $0E,$20,$1F,$60,$1A,$60,$0C,$00

            .byte $02,$00,$05,$00,$04,$00,$04,$10
            .byte $0C,$28,$0F,$C0,$0B,$80,$1D,$00
            .byte $3E,$00,$3E,$00,$1F,$80,$04,$C0
            .byte $0E,$40,$1F,$60,$1A,$60,$0C,$00

            .byte $FF,$FF,$80,$01,$A2,$23,$F7,$77
            .byte $F7,$77,$F7,$77,$F7,$77,$F7,$77
            .byte $F7,$77,$F7,$77,$F7,$77,$F7,$77
            .byte $F7,$77,$A2,$23,$80,$01,$7F,$FE

            .byte $FF,$FF,$80,$01,$C4,$45,$EE,$EF
            .byte $EE,$EF,$EE,$EF,$EE,$EF,$EE,$EF
            .byte $EE,$EF,$EE,$EF,$EE,$EF,$EE,$EF
            .byte $EE,$EF,$C4,$45,$80,$01,$7F,$FE

            .byte $FF,$FF,$80,$01,$88,$89,$5D,$DD
            .byte $5D,$DD,$5D,$DD,$5D,$DD,$5D,$DD
            .byte $5D,$DD,$5D,$DD,$5D,$DD,$5D,$DD
            .byte $5D,$DD,$88,$89,$80,$01,$7F,$FE

            .byte $FF,$FF,$80,$01,$91,$11,$BB,$BA
            .byte $BB,$BA,$BB,$BA,$BB,$BA,$BB,$BA
            .byte $BB,$BA,$BB,$BA,$BB,$BA,$BB,$BA
            .byte $BB,$BA,$91,$11,$80,$01,$7F,$FE

            .byte $00,$03,$00,$0E,$00,$2E,$00,$EE
            .byte $02,$EE,$0E,$EE,$2E,$EE,$6E,$EE
            .byte $6E,$EE,$22,$EE,$0C,$EE,$02,$2E
            .byte $00,$CE,$00,$22,$00,$0C,$00,$03

            .byte $00,$03,$00,$07,$00,$37,$00,$77
            .byte $03,$77,$07,$77,$37,$77,$77,$77
            .byte $57,$77,$33,$77,$04,$77,$03,$37
            .byte $00,$47,$00,$33,$00,$05,$00,$03

            .byte $00,$03,$00,$0B,$00,$3B,$00,$BB
            .byte $03,$BB,$0B,$BB,$3B,$BB,$7B,$BB
            .byte $4B,$BB,$33,$BB,$08,$BB,$03,$3B
            .byte $00,$8B,$00,$33,$00,$09,$00,$03

            .byte $00,$01,$00,$0D,$00,$1D,$00,$DD
            .byte $01,$DD,$0D,$DD,$1D,$DD,$5D,$DD
            .byte $4D,$DD,$15,$DD,$0C,$DD,$01,$5D
            .byte $00,$CD,$00,$15,$00,$0D,$00,$01

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $18,$00,$6E,$00,$5E,$00,$B7,$00
            .byte $AF,$00,$56,$00,$6E,$00,$18,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$0F,$00,$33,$C0
            .byte $6F,$E0,$5B,$E0,$B7,$F0,$AB,$F0
            .byte $97,$F0,$AF,$F0,$57,$E0,$6F,$E0
            .byte $31,$C0,$0F,$00,$00,$00,$00,$00

            .byte $07,$E0,$18,$78,$26,$FC,$55,$FE
            .byte $4B,$FE,$B7,$FF,$AB,$FF,$97,$FF
            .byte $AB,$FF,$B7,$FF,$AB,$FF,$55,$FE
            .byte $5A,$FE,$25,$7C,$18,$F8,$07,$E0

            .byte $00,$00,$00,$00,$00,$F0,$03,$1C
            .byte $04,$FE,$05,$BE,$0B,$7F,$0A,$BF
            .byte $09,$7F,$0A,$FF,$05,$7E,$06,$FE
            .byte $03,$3C,$00,$F0,$00,$00,$00,$00

            .byte $00,$00,$20,$00,$70,$00,$38,$00
            .byte $1C,$00,$0E,$08,$07,$0C,$03,$8C
            .byte $01,$FC,$00,$FC,$00,$48,$00,$78
            .byte $01,$F8,$03,$C0,$01,$C0,$00,$80

            .byte $03,$00,$03,$00,$03,$00,$03,$00
            .byte $03,$00,$03,$00,$03,$00,$03,$00
            .byte $03,$00,$03,$00,$03,$10,$37,$B0
            .byte $3D,$F0,$3E,$E0,$37,$80,$03,$00

            .byte $00,$00,$00,$04,$00,$0E,$00,$1C
            .byte $00,$38,$00,$70,$20,$E0,$71,$C0
            .byte $F3,$80,$7F,$00,$1B,$00,$1B,$00
            .byte $1F,$E0,$03,$C0,$00,$00,$00,$00

            .byte $00,$30,$00,$30,$00,$30,$00,$30
            .byte $00,$30,$00,$30,$00,$30,$00,$30
            .byte $00,$30,$00,$30,$00,$31,$03,$7B
            .byte $03,$DF,$03,$EE,$03,$78,$00,$30

            .byte $5E,$40,$77,$80,$19,$80,$FF,$C0
            .byte $D6,$C0,$F7,$40,$9A,$C0,$6F,$80
            .byte $5D,$80,$5F,$40,$A9,$00,$14,$80
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$09,$40,$07,$90,$2E,$E0
            .byte $17,$68,$35,$70,$5D,$50,$37,$B8
            .byte $3F,$50,$5A,$20,$25,$F0,$0F,$80
            .byte $0A,$40,$01,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$01,$20
            .byte $05,$C8,$03,$F4,$0E,$D8,$18,$FE
            .byte $0B,$AC,$1E,$66,$0D,$DC,$17,$52
            .byte $12,$F8,$05,$60,$02,$A0,$00,$80

            .byte $03,$84,$03,$0E,$01,$DA,$00,$F8
            .byte $16,$F6,$0E,$AC,$0A,$BA,$1D,$EC
            .byte $0A,$FC,$04,$5A,$0F,$A4,$01,$F0
            .byte $02,$50,$00,$80,$00,$00,$00,$00

            .byte $3B,$80,$7D,$C0,$1F,$C0,$1F,$80
            .byte $3D,$E0,$3E,$A0,$1E,$A0,$0F,$A0
            .byte $07,$A0,$07,$40,$3F,$00,$BF,$00
            .byte $1B,$80,$09,$80,$07,$00,$00,$00

            .byte $03,$80,$07,$C0,$03,$C0,$07,$E0
            .byte $0E,$F0,$0F,$6C,$07,$64,$03,$E4
            .byte $81,$E8,$45,$D8,$87,$C0,$2F,$C0
            .byte $46,$E0,$02,$60,$01,$C0,$00,$80

            .byte $03,$B8,$07,$DC,$01,$FC,$01,$F8
            .byte $03,$7E,$03,$BA,$01,$DA,$00,$FA
            .byte $00,$7E,$11,$76,$48,$F0,$11,$F0
            .byte $A3,$B8,$48,$98,$10,$70,$00,$20

            .byte $00,$38,$00,$7C,$00,$3C,$00,$7E
            .byte $00,$EE,$00,$F7,$00,$77,$10,$3D
            .byte $08,$1D,$44,$DF,$2A,$7D,$10,$3C
            .byte $22,$6E,$54,$E6,$08,$1C,$00,$08

            .byte $1C,$00,$3E,$00,$3C,$00,$7E,$00
            .byte $77,$00,$EF,$00,$EE,$00,$BC,$08
            .byte $B8,$10,$FB,$22,$BE,$54,$3C,$08
            .byte $76,$44,$67,$2A,$38,$10,$10,$00

            .byte $1D,$C0,$3B,$E0,$3F,$80,$1F,$80
            .byte $7E,$C0,$5D,$C0,$5B,$80,$5F,$00
            .byte $7E,$00,$6E,$88,$0F,$12,$0F,$88
            .byte $1D,$C5,$19,$12,$0E,$08,$04,$00

            .byte $01,$C0,$03,$E0,$03,$C0,$07,$E0
            .byte $0F,$70,$36,$F0,$26,$E0,$27,$C0
            .byte $17,$81,$1B,$A2,$03,$E1,$03,$F4
            .byte $07,$62,$06,$40,$03,$80,$01,$00

            .byte $01,$DC,$03,$BE,$03,$F8,$01,$F8
            .byte $07,$BC,$05,$7C,$05,$78,$05,$F0
            .byte $05,$E0,$02,$E0,$00,$FC,$00,$FD
            .byte $01,$D8,$01,$90,$00,$E0,$00,$40

            .byte $07,$84,$04,$8A,$03,$80,$03,$84
            .byte $03,$CE,$07,$FF,$1C,$EF,$77,$6D
            .byte $BF,$6D,$07,$7D,$03,$7D,$03,$DD
            .byte $05,$CD,$05,$CD,$05,$CF,$03,$80

            .byte $07,$8A,$04,$80,$03,$84,$03,$84
            .byte $03,$CE,$07,$FF,$1C,$EF,$B7,$6D
            .byte $7F,$6D,$07,$7D,$03,$7D,$03,$DD
            .byte $05,$CD,$05,$CD,$05,$CF,$03,$80

            .byte $5D,$80,$C8,$C0,$91,$00,$3B,$80
            .byte $00,$00,$2A,$00,$15,$00,$00,$00
            .byte $7F,$80,$D5,$40,$EA,$C0,$FF,$C0
            .byte $EA,$C0,$D5,$40,$AA,$C0,$FF,$C0

            .byte $1D,$C0,$08,$90,$31,$30,$1B,$A0
            .byte $00,$00,$05,$40,$0A,$80,$00,$00
            .byte $1F,$E0,$37,$50,$2E,$B0,$37,$50
            .byte $2E,$B0,$3F,$F0,$2A,$B0,$3F,$F0

            .byte $05,$D8,$0C,$8C,$09,$10,$03,$B8
            .byte $00,$00,$02,$A0,$01,$50,$00,$00
            .byte $07,$F8,$0D,$74,$0A,$EC,$0F,$FC
            .byte $0A,$EC,$0D,$74,$0A,$AC,$0F,$FC

            .byte $01,$DC,$00,$89,$03,$13,$01,$BA
            .byte $00,$00,$00,$54,$00,$A8,$00,$00
            .byte $01,$FE,$03,$FF,$02,$AB,$03,$57
            .byte $02,$AB,$03,$57,$02,$AB,$03,$FF

            .byte $80,$01,$FF,$FF,$EB,$AB,$BE,$FF
            .byte $FF,$FB,$AF,$AF,$FF,$FF,$FF,$FF
            .byte $00,$00,$FF,$FF,$E1,$9F,$E1,$9F
            .byte $FF,$FF,$9E,$67,$9E,$67,$FF,$FF

            .byte $80,$01,$FF,$FF,$FA,$AF,$AF,$FB
            .byte $AF,$BF,$FA,$EB,$FF,$FF,$FF,$FF
            .byte $00,$00,$FF,$FF,$9E,$67,$9E,$67
            .byte $FF,$FF,$E1,$9F,$E1,$9F,$FF,$FF

            .byte $FF,$FF,$FF,$FF,$EB,$AF,$FF,$FF
            .byte $00,$00,$FF,$FF,$BB,$EF,$FF,$FF
            .byte $80,$01,$FF,$FF,$CE,$79,$A4,$BF
            .byte $95,$37,$CE,$7F,$FF,$F7,$FF,$FF

            .byte $FF,$FF,$FF,$FF,$EB,$BB,$FF,$FF
            .byte $00,$00,$FF,$FF,$BB,$DF,$FF,$FF
            .byte $80,$01,$FF,$FF,$CE,$79,$95,$37
            .byte $A4,$BF,$CE,$7F,$FF,$F7,$FF,$FF

            .byte $00,$00,$7F,$FE,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $5C,$8D,$A3,$72,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$FF,$FF,$7F,$FE,$00,$00

            .byte $00,$00,$1F,$F0,$3B,$FC,$75,$56
            .byte $6A,$AA,$DD,$7F,$D5,$BF,$E2,$BF
            .byte $A2,$BF,$D5,$BF,$ED,$BF,$7B,$7E
            .byte $66,$FE,$3D,$FC,$1B,$F0,$00,$00

            .byte $00,$00,$03,$C0,$0C,$30,$13,$C8
            .byte $2D,$F4,$2B,$D4,$56,$6A,$6C,$36
            .byte $6C,$56,$5A,$7A,$25,$DC,$2F,$B4
            .byte $13,$C8,$0C,$30,$03,$C0,$00,$00

            .byte $00,$00,$0F,$F8,$3F,$DC,$7F,$2E
            .byte $7E,$D6,$FE,$BB,$FD,$AB,$FD,$57
            .byte $FD,$45,$FD,$AB,$FD,$B7,$2A,$DE
            .byte $57,$66,$3F,$BC,$0F,$F8,$00,$00

            .byte $03,$C0,$0C,$30,$13,$C8,$2E,$B4
            .byte $5E,$8A,$56,$9A,$B2,$B5,$B8,$E5
            .byte $BC,$C5,$BE,$85,$5E,$8A,$5E,$8A
            .byte $2E,$B4,$13,$C8,$0C,$30,$03,$C0

            .byte $00,$00,$00,$00,$03,$C0,$0E,$B0
            .byte $1E,$8C,$76,$9A,$BA,$A5,$BC,$C5
            .byte $BE,$85,$9E,$89,$4E,$B2,$33,$CC
            .byte $0C,$30,$03,$C0,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$7F,$FE,$D5,$55
            .byte $80,$01,$7F,$FE,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$03,$C0,$0C,$30
            .byte $13,$C8,$6E,$B4,$D6,$9B,$BA,$A5
            .byte $BC,$C5,$BE,$85,$7E,$8E,$3E,$8C
            .byte $0E,$B0,$03,$C0,$00,$00,$00,$00

            .byte $01,$00,$02,$80,$00,$80,$00,$80
            .byte $00,$80,$01,$80,$02,$C2,$7D,$E1
            .byte $85,$FE,$42,$40,$01,$80,$01,$00
            .byte $01,$00,$01,$00,$01,$40,$00,$80

            .byte $02,$00,$05,$00,$01,$00,$01,$00
            .byte $01,$00,$01,$82,$02,$C1,$05,$FE
            .byte $7D,$E0,$82,$40,$41,$80,$00,$80
            .byte $00,$80,$00,$80,$00,$A0,$00,$40

            .byte $00,$00,$08,$00,$14,$00,$02,$04
            .byte $02,$02,$03,$84,$02,$F8,$05,$E0
            .byte $05,$E0,$1E,$40,$21,$C0,$40,$40
            .byte $20,$40,$00,$28,$00,$10,$00,$00

            .byte $00,$00,$00,$10,$00,$08,$20,$10
            .byte $58,$10,$05,$A0,$02,$C0,$05,$E0
            .byte $05,$E0,$02,$40,$05,$A0,$08,$1A
            .byte $08,$04,$10,$00,$08,$00,$00,$00

            .byte $0F,$F0,$31,$8C,$C3,$C3,$C2,$C3
            .byte $B1,$8D,$CF,$F3,$70,$0E,$2F,$FC
            .byte $2F,$FC,$2B,$EC,$16,$B8,$17,$F8
            .byte $17,$F8,$09,$B0,$06,$E0,$01,$80

            .byte $00,$00,$00,$00,$FF,$FF,$80,$01
            .byte $57,$FE,$4A,$FE,$6B,$FE,$2B,$FC
            .byte $2B,$FC,$2B,$FC,$15,$F8,$17,$F8
            .byte $0A,$F0,$09,$F0,$06,$E0,$01,$80

            .byte $0F,$F0,$30,$1C,$CF,$E7,$99,$FB
            .byte $B7,$FD,$B5,$5D,$6B,$F6,$2F,$FC
            .byte $2B,$FC,$2E,$BC,$13,$E8,$17,$F8
            .byte $17,$F8,$0F,$F0,$06,$60,$01,$80

            .byte $00,$00,$00,$00,$FF,$FF,$80,$01
            .byte $57,$FE,$4A,$FE,$6B,$FE,$2B,$FC
            .byte $2B,$FC,$2B,$FC,$15,$F8,$17,$F8
            .byte $0A,$F0,$09,$F0,$06,$E0,$01,$80

            .byte $03,$C0,$0C,$30,$14,$08,$22,$04
            .byte $42,$02,$43,$86,$82,$79,$84,$21
            .byte $84,$21,$9E,$41,$61,$C2,$40,$42
            .byte $20,$44,$10,$28,$0C,$30,$03,$C0

            .byte $03,$C0,$0C,$B0,$10,$88,$20,$84
            .byte $40,$82,$41,$82,$82,$41,$FC,$21
            .byte $84,$3F,$82,$41,$41,$82,$41,$02
            .byte $21,$04,$11,$08,$0D,$30,$03,$C0

            .byte $03,$C0,$0C,$30,$10,$28,$20,$44
            .byte $40,$42,$61,$C2,$9E,$41,$84,$21
            .byte $84,$21,$82,$79,$43,$86,$42,$02
            .byte $22,$04,$14,$08,$0C,$30,$03,$C0

            .byte $03,$C0,$0C,$30,$10,$08,$30,$0C
            .byte $48,$12,$45,$A2,$82,$41,$84,$21
            .byte $84,$21,$82,$41,$45,$A2,$48,$12
            .byte $30,$0C,$10,$08,$0C,$30,$03,$C0

            .byte $19,$80,$3C,$C0,$0F,$C0,$37,$80
            .byte $3B,$C0,$FE,$C0,$E5,$40,$52,$80
            .byte $25,$00,$1E,$00,$00,$00,$3F,$00
            .byte $56,$80,$1A,$00,$16,$00,$1E,$00

            .byte $07,$80,$01,$80,$03,$E0,$0D,$E0
            .byte $0E,$F0,$3F,$B0,$39,$50,$1C,$A0
            .byte $09,$40,$07,$80,$0F,$C0,$15,$A0
            .byte $06,$80,$05,$80,$07,$80,$00,$00

            .byte $01,$98,$03,$CC,$00,$FC,$03,$78
            .byte $03,$BC,$0F,$EC,$0E,$54,$05,$28
            .byte $02,$50,$01,$E0,$03,$F0,$05,$68
            .byte $01,$A0,$01,$60,$01,$E0,$00,$00

            .byte $00,$3C,$00,$0C,$00,$1E,$00,$6F
            .byte $00,$77,$01,$FD,$01,$CB,$00,$A5
            .byte $00,$4A,$00,$3C,$00,$00,$00,$7E
            .byte $00,$AD,$00,$34,$00,$2C,$00,$3C

            .byte $3C,$00,$30,$00,$78,$00,$F6,$00
            .byte $EE,$00,$BF,$80,$D3,$80,$A5,$00
            .byte $52,$00,$3C,$00,$00,$00,$7E,$00
            .byte $B5,$00,$2C,$00,$34,$00,$3C,$00

            .byte $19,$80,$33,$C0,$3F,$00,$1E,$C0
            .byte $3D,$C0,$37,$F0,$2A,$70,$14,$A0
            .byte $0A,$40,$07,$80,$0F,$C0,$16,$A0
            .byte $05,$80,$06,$80,$07,$80,$00,$00

            .byte $01,$E0,$01,$80,$07,$C0,$07,$B0
            .byte $0F,$70,$0D,$FC,$0A,$9C,$05,$38
            .byte $02,$90,$01,$E0,$03,$F0,$05,$A8
            .byte $01,$60,$01,$A0,$01,$E0,$00,$00

            .byte $01,$98,$03,$3C,$03,$F0,$01,$EC
            .byte $03,$DC,$03,$7F,$02,$A7,$01,$4A
            .byte $00,$A4,$00,$78,$00,$00,$00,$FC
            .byte $01,$6A,$00,$58,$00,$68,$00,$78

            .byte $00,$03,$00,$0D,$00,$31,$00,$CD
            .byte $03,$39,$0C,$F5,$33,$F9,$C7,$F5
            .byte $AF,$F9,$97,$F5,$AF,$F9,$97,$F5
            .byte $AF,$F9,$97,$F5,$A8,$09,$FF,$FF

            .byte $1F,$3E,$2F,$3D,$2D,$3D,$2F,$39
            .byte $15,$3A,$17,$3A,$2D,$39,$2F,$3D
            .byte $2D,$3D,$2F,$3D,$2D,$3D,$2F,$3D
            .byte $2D,$3D,$2F,$3D,$2F,$3D,$3F,$3F

            .byte $3B,$C0,$1B,$80,$1B,$80,$1B,$80
            .byte $1B,$80,$1F,$80,$1F,$80,$0D,$80
            .byte $1F,$80,$3E,$C0,$78,$60,$F0,$30
            .byte $6F,$30,$EF,$00,$0D,$00,$06,$00

            .byte $01,$C0,$09,$80,$09,$90,$09,$B8
            .byte $0D,$F4,$05,$A0,$06,$C0,$03,$C0
            .byte $03,$F0,$03,$F8,$03,$CC,$00,$1F
            .byte $03,$C6,$03,$F7,$03,$40,$01,$80

            .byte $00,$D8,$03,$56,$01,$DC,$01,$DC
            .byte $01,$FC,$00,$F8,$00,$F8,$00,$F8
            .byte $01,$F8,$07,$FC,$06,$F6,$06,$0F
            .byte $00,$F6,$00,$F7,$00,$F0,$00,$60

            .byte $00,$38,$00,$19,$00,$99,$01,$D9
            .byte $02,$FB,$00,$5A,$00,$36,$00,$3C
            .byte $00,$FC,$01,$FC,$03,$3C,$0F,$80
            .byte $06,$3C,$0E,$FC,$00,$2C,$00,$18

            .byte $11,$00,$20,$80,$71,$C0,$BB,$A0
            .byte $1F,$00,$0E,$00,$1F,$80,$9F,$C0
            .byte $5E,$00,$FF,$C0,$5F,$80,$9F,$00
            .byte $0F,$20,$19,$E0,$39,$E0,$1F,$20

            .byte $06,$C0,$1C,$70,$06,$C0,$06,$C0
            .byte $03,$80,$03,$80,$27,$E0,$17,$F0
            .byte $17,$F0,$3F,$F0,$17,$E0,$17,$C0
            .byte $23,$C4,$06,$7C,$0E,$7C,$07,$C4

            .byte $01,$F0,$00,$E0,$00,$E0,$00,$E0
            .byte $00,$E0,$00,$E0,$01,$F8,$09,$FC
            .byte $05,$E0,$0F,$FC,$05,$F8,$09,$F0
            .byte $00,$F2,$01,$9E,$03,$9E,$01,$F2

            .byte $00,$6C,$01,$C7,$00,$6C,$00,$6C
            .byte $00,$38,$00,$38,$00,$7F,$00,$7C
            .byte $00,$78,$02,$FC,$00,$7F,$00,$7C
            .byte $00,$3D,$00,$67,$00,$E7,$00,$7D

            .byte $36,$00,$E3,$80,$36,$00,$36,$00
            .byte $1C,$00,$1C,$00,$FE,$00,$3E,$00
            .byte $1E,$00,$3F,$C0,$FE,$00,$3E,$00
            .byte $BC,$00,$E6,$00,$E7,$00,$BE,$00

            .byte $0F,$80,$07,$00,$07,$00,$07,$00
            .byte $07,$00,$07,$00,$1F,$80,$3F,$90
            .byte $07,$A0,$3F,$F0,$1F,$A0,$0F,$90
            .byte $4F,$00,$79,$80,$79,$C0,$4F,$80

            .byte $03,$60,$0E,$38,$03,$60,$03,$60
            .byte $01,$C0,$01,$C0,$07,$E4,$0F,$E8
            .byte $0F,$E8,$0F,$FC,$07,$E8,$03,$E8
            .byte $23,$C4,$3E,$60,$3E,$70,$23,$E0

            .byte $00,$00,$01,$04,$03,$8E,$05,$DD
            .byte $00,$F8,$00,$70,$01,$F8,$03,$F9
            .byte $00,$7A,$03,$FF,$01,$FA,$00,$F9
            .byte $04,$F0,$07,$98,$07,$9C,$04,$F8

            .byte $7F,$FE,$08,$10,$04,$20,$08,$10
            .byte $04,$20,$08,$10,$04,$20,$08,$10
            .byte $04,$20,$08,$10,$04,$20,$08,$10
            .byte $04,$20,$08,$10,$04,$20,$7F,$FE

            .byte $06,$60,$02,$40,$02,$40,$0F,$F0
            .byte $0F,$F0,$0F,$F0,$14,$98,$37,$6C
            .byte $3F,$FC,$1F,$F8,$07,$C0,$07,$20
            .byte $07,$20,$06,$20,$06,$20,$03,$C0

            .byte $02,$60,$06,$40,$02,$40,$0F,$F0
            .byte $0F,$F0,$0F,$F0,$14,$98,$37,$6C
            .byte $3F,$FC,$1F,$F8,$07,$C0,$07,$20
            .byte $07,$20,$06,$20,$06,$20,$07,$C0

            .byte $06,$60,$02,$40,$02,$40,$0F,$F0
            .byte $0F,$F0,$0F,$F0,$14,$92,$37,$66
            .byte $3F,$FE,$1F,$FC,$07,$C0,$07,$20
            .byte $07,$20,$06,$20,$06,$20,$07,$C0

            .byte $06,$60,$02,$40,$02,$40,$0F,$F0
            .byte $0F,$F0,$0F,$F0,$14,$90,$37,$60
            .byte $3F,$FE,$1F,$FF,$07,$C0,$07,$20
            .byte $07,$20,$06,$20,$06,$20,$03,$C0

            .byte $0F,$FB,$0F,$FB,$1F,$DB,$1F,$DF
            .byte $3F,$EE,$3F,$F0,$3F,$F8,$00,$08
            .byte $00,$2F,$00,$CF,$03,$0F,$0C,$0F
            .byte $30,$0F,$00,$0F,$00,$3F,$00,$0F

            .byte $0F,$FB,$0F,$FB,$1F,$DB,$1F,$DF
            .byte $3F,$EE,$3F,$F0,$3F,$F8,$00,$08
            .byte $3F,$EF,$00,$0F,$00,$0F,$00,$0F
            .byte $00,$0F,$00,$0F,$00,$3F,$00,$0F

            .byte $0F,$FB,$0F,$FB,$1F,$DB,$1F,$DF
            .byte $3F,$EE,$3F,$F0,$3F,$F8,$00,$08
            .byte $0F,$CF,$47,$CF,$7F,$8F,$7F,$8F
            .byte $01,$8F,$01,$8F,$01,$BF,$03,$AF

            .byte $0F,$FB,$0F,$FB,$1F,$DB,$1F,$DF
            .byte $3F,$EE,$3F,$F0,$3F,$F8,$00,$08
            .byte $0F,$CF,$07,$CF,$0E,$8F,$5D,$8F
            .byte $3B,$2F,$1E,$2F,$04,$3F,$00,$0F

            .byte $07,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$10,$00,$0A,$00,$15,$98
            .byte $2A,$F4,$1D,$98,$2F,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$03,$C0,$07,$EC
            .byte $0E,$BA,$05,$6C,$0A,$80,$01,$40
            .byte $02,$80,$05,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$01,$00,$00,$A0,$01,$58
            .byte $02,$AE,$01,$DD,$02,$F6,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $3C,$00,$13,$00,$14,$00,$1E,$00
            .byte $22,$00,$21,$80,$43,$00,$4F,$00
            .byte $5D,$00,$5A,$00,$3A,$00,$3A,$00
            .byte $2E,$00,$D4,$00,$3C,$00,$18,$00

            .byte $07,$00,$02,$00,$02,$00,$07,$80
            .byte $08,$80,$08,$40,$10,$60,$11,$C0
            .byte $17,$80,$1F,$00,$0E,$80,$0E,$80
            .byte $0B,$80,$3F,$00,$0F,$00,$06,$00

L4180:      .byte $01,$40,$06,$30,$01,$40,$01,$E0
            .byte $02,$20,$02,$18,$04,$30,$04,$F0
            .byte $05,$D0,$05,$A0,$03,$A0,$03,$A0
            .byte $0A,$E0,$05,$40,$0B,$C0,$01,$80

            .byte $00,$74,$00,$22,$00,$25,$00,$78
            .byte $00,$88,$00,$86,$01,$0C,$01,$3C
            .byte $01,$74,$01,$68,$00,$E8,$00,$E8
            .byte $00,$B8,$03,$50,$00,$B0,$00,$60

            .byte $2E,$00,$44,$00,$A4,$00,$1E,$00
            .byte $11,$00,$61,$00,$30,$80,$3C,$80
            .byte $2E,$80,$16,$80,$17,$00,$17,$00
            .byte $1D,$00,$0A,$C0,$0D,$00,$06,$00

            .byte $02,$80,$0C,$60,$02,$80,$07,$80
            .byte $04,$40,$18,$40,$0C,$20,$0F,$20
            .byte $0B,$A0,$05,$A0,$05,$C0,$05,$C0
            .byte $07,$50,$02,$A0,$03,$D0,$01,$80

;------------------------------------------------
; Willy sprite data
;------------------------------------------------

L4800:
            .byte $31,$C0,$70,$C0,$5B,$80,$1F,$00
            .byte $6F,$60,$7F,$E0,$3F,$C0,$1F,$80
            .byte $0F,$00,$06,$00,$0F,$00,$1F,$00
            .byte $0B,$00,$1F,$80,$0F,$00,$0F,$00
L4820:
            .byte $0E,$E0,$07,$60,$06,$E0,$03,$C0
            .byte $0D,$F0,$0E,$F0,$07,$E0,$07,$E0
            .byte $03,$C0,$01,$80,$03,$C0,$07,$C0
            .byte $02,$C0,$07,$E0,$03,$C0,$03,$C0
L4840:
            .byte $00,$E0,$00,$60,$00,$60,$00,$F0
            .byte $01,$B8,$01,$D8,$01,$D8,$01,$D8
            .byte $00,$F0,$00,$60,$00,$F0,$01,$F0
            .byte $00,$B0,$01,$F8,$00,$F0,$00,$F0
L4860:
            .byte $00,$EE,$00,$76,$00,$6E,$00,$3C
            .byte $00,$DF,$00,$EF,$00,$7E,$00,$7E
            .byte $00,$3C,$00,$18,$00,$3C,$00,$7C
            .byte $00,$2C,$00,$7E,$00,$3C,$00,$3C
L4880:
            .byte $77,$00,$6E,$00,$76,$00,$3C,$00
            .byte $FB,$00,$F7,$00,$7E,$00,$7E,$00
            .byte $3C,$00,$18,$00,$3C,$00,$3E,$00
            .byte $34,$00,$7E,$00,$3C,$00,$3C,$00
L48A0:
            .byte $07,$00,$06,$00,$06,$00,$0F,$00
            .byte $1D,$80,$1B,$80,$1B,$80,$1B,$80
            .byte $0F,$00,$06,$00,$0F,$00,$0F,$80
            .byte $0D,$00,$1F,$80,$0F,$00,$0F,$00
L48C0:
            .byte $07,$70,$06,$E0,$07,$60,$03,$C0
            .byte $0F,$B0,$0F,$70,$07,$E0,$07,$E0
            .byte $03,$C0,$01,$80,$03,$C0,$03,$E0
            .byte $03,$40,$07,$E0,$03,$C0,$03,$C0
L48E0:
            .byte $03,$8C,$03,$0E,$01,$DA,$00,$F8
            .byte $06,$F6,$07,$FE,$03,$FC,$01,$F8
            .byte $00,$F0,$00,$60,$00,$F0,$00,$F8
            .byte $00,$D0,$01,$F8,$00,$F0,$00,$F0

;------------------------------------------------

L4200:      jmp L4206              ; 4C 06 42
            jmp L4366              ; 4C 66 43
L4206:      lda L0055              ; A5 55
            cmp #$06               ; C9 06
            beq L4218              ; F0 0C
            cmp #$3B               ; C9 3B
            beq L4218              ; F0 08
            cmp #$33               ; C9 33
            beq L4218              ; F0 04
            cmp #$19               ; C9 19
            bne L421E              ; D0 06
L4218:      lda L0A26              ; AD 26 0A
            sta L0A25              ; 8D 25 0A
L421E:      jsr L430A              ; 20 0A 43
            jsr L4227              ; 20 27 42
            jmp L4292              ; 4C 92 42
L4227:      lda L0055              ; A5 55
            cmp #$16               ; C9 16
            beq L4231              ; F0 04
            cmp #$30               ; C9 30
            bne L427E              ; D0 4D
L4231:      lda L427F              ; AD 7F 42
            eor #$FE               ; 49 FE
            sta L427F              ; 8D 7F 42
            lda L4280              ; AD 80 42
            eor #$01               ; 49 01
            sta L4280              ; 8D 80 42
            sta L4281              ; 8D 81 42
L4244:      ldx L4281              ; AE 81 42
            lda L4282,X            ; BD 82 42
            clc                    ; 18
            adc L427F              ; 6D 7F 42
            and #$1F               ; 29 1F
            sta L4282,X            ; 9D 82 42
            sta L0070              ; 85 70
            lda L428A,X            ; BD 8A 42
            sta L0071              ; 85 71
            lda L427F              ; AD 7F 42
            and #$04               ; 29 04
            sta L0072              ; 85 72
            jsr L110F              ; 20 0F 11
            lda L0072              ; A5 72
            eor #$04               ; 49 04
            sta L0072              ; 85 72
            lda L0070              ; A5 70
            clc                    ; 18
            adc #$05               ; 69 05
            and #$1F               ; 29 1F
            sta L0070              ; 85 70
            jsr L110F              ; 20 0F 11
            dec L4281              ; CE 81 42
            dec L4281              ; CE 81 42
            bpl L4244              ; 10 C6
L427E:      rts                    ; 60
L427F:      .byte $01
L4280:      .byte $07
L4281:      .byte $00
L4282:      .byte $14,$08,$07,$00,$10,$10,$03,$18
L428A:      .byte $05,$05,$02,$02,$0B,$0B,$08,$08
L4292:      lda L0064              ; A5 64
            bne L42CA              ; D0 34
            ldx #$02               ; A2 02
L4298:      lda L0055              ; A5 55
            cmp L42CB,X            ; DD CB 42
            bne L42C7              ; D0 28
            lda L0A24              ; AD 24 0A
            cmp #$2C               ; C9 2C
            bcs L42C7              ; B0 21
            lda L0A1B              ; AD 1B 0A
            cmp L42CE,X            ; DD CE 42
            bne L42C7              ; D0 19
            lda L42D1,X            ; BD D1 42
            sta L0A1B              ; 8D 1B 0A
            lda L42D4,X            ; BD D4 42
            sta L0A24              ; 8D 24 0A
            lda L42D7,X            ; BD D7 42
            sta L0096              ; 85 96
            jsr L4366              ; 20 66 43
            lda L0096              ; A5 96
            jmp L1118              ; 4C 18 11
L42C7:      dex                    ; CA
            bpl L4298              ; 10 CE
L42CA:      rts                    ; 60

L42CB:      .byte $01,$01,$1D
L42CE:      .byte $30,$80,$E8
L42D1:      .byte $10,$A8,$90
L42D4:      .byte $08,$68,$58
L42D7:      .byte $17,$12,$01

;--------------------------------------------
; Scroll rocket up
;--------------------------------------------

L42DA:
            lda #>$8109               ; A9 5D
            sta L0091              ; 85 91
            lda #>$8209               ; A9 5E
            sta L0093              ; 85 93

            ldx #$0e               ; A2 0F
	stx y_cnt
L42EC:      ldy #13               ; A0 68
	sty x_cnt
            lda #<$8209               ; A9 68
            sta L0090              ; 85 90
            lda #<$8309               ; A9 A8
            sta L0092              ; 85 92
L42ED:
	ldx #7
L42EE:
	ldy scrtab,x
            lda (L0092),Y          ; B1 92
            sta (L0090),Y          ; 91 90
	dex
	bpl L42EE

	inc L0090
	inc L0092
	dec x_cnt
            bne L42ED              ; D0 F9

	inc L0091
	inc L0093
	dec y_cnt
	 
;            lda L0092              ; A5 92
;            sta L0090              ; 85 90
;            clc                    ; 18
;            adc #$40               ; 69 40
;            sta L0092              ; 85 92
;            lda L0093              ; A5 93
;            sta L0091              ; 85 91
;            adc #$01               ; 69 01
;            sta L0093              ; 85 93
;            dex                    ; CA
            bne L42EC              ; D0 E3
            rts                    ; 60

x_cnt:	.byte 0
y_cnt:	.byte 0

;--------------------------------------------
; Let rocket fly 
;--------------------------------------------

L430A:      lda L0A80              ; AD 80 0A
            ora L0A81              ; 0D 81 0A
            bne L4352              ; D0 40

            lda L0055              ; A5 55
            cmp #$1F               ; C9 1F
            bne L4353              ; D0 3B

            lda L0064              ; A5 64
            bne L4352              ; D0 36

            lda #$32               ; Set scroll counter
            sta L007B              ; 85 7B

L4320:      jsr L42DA              ; Scroll rocket

; Wait loop
            ldx #$35               ; A2 35
L4325:      dey                    ; 88
            bne L4325              ; D0 FD
            dex                    ; CA
            bne L4325              ; D0 FA

; Adjust fire data pointer

            lda L007B              ; A5 7B
            and #$07               ; 29 07
            adc #>L1100               ; 69 11
            sta L4336+2             ; 
            sta L4337+2             ; 
            sta L4338+2             ; 
            sta L4339+2             ; 
            sta L433A+2             ; 
            sta L433B+2             ; 
            sta L433C+2             ; 
            sta L433D+2             ; 

; Display rocket fire

            ldy #6               ; A0 30
L4336:	lda L1100,Y            ; B9 00 11'
	sta $8f0c,Y            ; 99 47 70
L4337:	lda L1100+6,Y            ; B9 00 11
	sta $8f2c,Y            ; 99 47 70
L4338:	lda L1100+12,Y            ; B9 00 11
	sta $8f4c,Y            ; 99 47 70
L4339:	lda L1100+18,Y            ; B9 00 11
	sta $8f6c,Y            ; 99 47 70
L433A:	lda L1100+24,Y            ; B9 00 11
	sta $8f8c,Y            ; 99 47 70
L433B:	lda L1100+30,Y            ; B9 00 11
	sta $8fac,Y            ; 99 47 70
L433C:	lda L1100+36,Y            ; B9 00 11
	sta $8fcc,Y            ; 99 47 70
L433D:	lda L1100+42,Y            ; B9 00 11
	sta $8fec,Y            ; 99 47 70

            dey                    ; 88
            bne L4336              ; D0 F7

            dec L007B              ; C6 7B
            bne L4320              ; D0 DD

; Jump to Docking Bay

            lda #$68               ; A9 68
            sta L0A24              ; 8D 24 0A
            lda #$70               ; A9 70
            sta L0A1B              ; 8D 1B 0A
            lda #$13               ; A9 13
            jsr L1118              ; 20 18 11

L4352:      rts                    ; 60

;---------------------------------------------

L4353:      cmp #$08               ; C9 08
            bne L4365              ; D0 0E
            ldx #$01               ; A2 01
            lda L0A25              ; AD 25 0A
            cmp #$60               ; C9 60
            bcc L4362              ; 90 02
L4360:      ldx #$00               ; A2 00
L4362:      stx L0A2E              ; 8E 2E 0A
L4365:      rts                    ; 60
L4366:      ldx #$00               ; A2 00
L4368:      stx L007B              ; 86 7B
            lda L1180,X            ; BD 80 11
            sta $00                ; 85 00
            sta L0001              ; 85 01

;            lda #$13               ; A9 13
;            jsr OSBYTE              ; 20 F4 FF

            ldx L007B              ; A6 7B
            dex                    ; CA
            bne L4368              ; D0 ED
            rts                    ; 60

	.byte $EE,$FF,$A2,$50
L4380:
            clc
            adc #$01               ; 69 01
            bne L4380              ; D0 FB
            dex                    ; CA
            bne L4380              ; D0 F8
            dey                    ; 88
            bpl L4362+1              ; 10 D8
            dec L007B              ; C6 7B
            bpl L4360+1              ; 10 D2
            rts                    ; 60

            .byte $00,$04,$01,$02,$05,$06,$03,$07
            .byte $03
L4399:      .byte $60,$03,$60,$00,$00,$00,$00,$07
            .byte $10,$03,$38,$03,$74,$03,$E0,$03
            .byte $E1,$02,$22,$05,$D5,$02,$2A,$07
            .byte $F4,$0B,$E0,$56,$A0,$A9,$C0,$56
            .byte $30,$06,$30,$00,$00,$00,$00,$1D
            .byte $C0,$45,$00,$AA,$84,$55,$44,$2A
            .byte $A4,$15,$50,$07,$2C,$08,$82,$12
            .byte $44,$2F,$E0,$2B,$E4,$17,$44,$15
            .byte $C4,$0A,$84,$05,$0E,$02,$04,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Shadow screen
;------------------------------------------------

L4400:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
L4500:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------

L4600:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
L4620:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

L4660:      .byte $00,$00,$43,$FE,$43,$00,$00,$00
            .byte $00,$00,$33,$EE,$33,$00,$00,$00
L4670:
            .byte $00,$00,$C2,$7F,$C2,$00,$00,$00
            .byte $00,$00,$22,$FF,$22,$00,$00,$00

L4680:      .byte $00,$00,$00,$00,$00,$00,$00,$00
L4688:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

L46A0:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

L46B0:      .byte $00,$00,$01,$02,$0A,$0E,$12,$13
            .byte $15,$16,$1A,$1E,$22,$26,$2A,$2E
            .byte $32,$36,$3A,$3E,$42,$4A,$4C,$50
            .byte $52,$54,$58,$5C,$60,$64,$68,$70
            .byte $71,$72,$76,$7E,$7F,$83,$87,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$85
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
;------------------------------------------------
; Program entry
;------------------------------------------------

L4700:
	lda #0
	tax
zloop:
	sta 0,x
	inx
	bne zloop

	jsr vdu22		; CLEAR4
	jsr vdu12		; CLS

;            jsr L5700              ; 20 00 57

	lda #$1f
	sta L0094		; Nr of bytes to plot for sprite

	lda #8
	sta L0095

            jmp L0B21              ; Jump game loop

;------------------------------------------------
; VDU codes
;------------------------------------------------

L472B:      .byte $16,$04
            .byte $17,$00,$0A,$20,$00,$00,$00,$00,$00,$00
            .byte $00,$00
            .byte $0C
            .byte $1C,$04,$1E,$23,$04
            .byte $00

;------------------------------------------------

            .byte $00,$EE,$EE
            .byte $00,$00,$77,$66,$00,$00,$66,$EE
            .byte $00,$00,$33,$CC,$00,$00,$DD,$FF
            .byte $00,$00,$EE,$FF,$00,$00,$77,$EE
            .byte $00,$00,$77,$EE,$00,$00,$33,$CC
            .byte $00,$00,$11,$88,$00,$00,$33,$CC
            .byte $00,$00,$77,$CC,$00,$00,$22,$CC
            .byte $00,$00,$77,$EE,$00,$00,$33,$CC
            .byte $00,$00,$33,$CC,$00,$00,$00,$EE
            .byte $00,$00,$00,$66,$00,$00,$00,$66
            .byte $00,$00,$00,$FF,$00,$00,$11,$BB
            .byte $88,$00,$11,$DD,$88,$00,$11,$DD
            .byte $88,$00,$11,$DD,$88,$00,$00,$FF
            .byte $00,$00,$00,$66,$00,$00,$00,$FF
            .byte $00,$00,$11,$FF,$00,$00,$00,$BB
            .byte $00,$00,$11,$FF,$88,$00,$00,$FF
            .byte $00,$00,$00,$FF,$00,$00,$00,$EE
            .byte $EE,$00,$00,$77,$66,$00,$00,$66
            .byte $EE,$00,$00,$33,$CC,$00,$00,$DD
            .byte $FF,$00,$00,$EE,$FF,$00,$00,$77
            .byte $EE,$00,$00,$77,$EE,$00,$00,$33
            .byte $CC,$00,$00,$11,$88,$00,$00,$33
            .byte $CC,$00,$00,$77,$CC,$00,$00,$22
            .byte $CC,$00,$00,$77,$EE,$00,$00,$33
            .byte $CC,$00,$00,$33,$CC

;------------------------------------------------

L4900:      .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Copy L4980-L49FF -> L0880-L08FF
;------------------------------------------------

L4980:      .byte $12,$00,$F8,$FF,$EA,$00,$01,$00
            .byte $12,$00,$01,$00,$46,$00,$0A,$00
            .byte $11,$00,$04,$00,$5A,$00,$08,$00
            .byte $12,$00,$02,$00,$AA,$00,$0A,$00
            .byte $10,$00,$03,$00,$05,$00,$0A,$00
            .byte $10,$00,$F3,$FF,$07,$00,$04,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$89,$DE,$01
            .byte $02,$04,$04,$04,$0A,$0A,$0A,$0A
            .byte $00,$00,$EC,$5A,$5A,$00,$00,$00
            .byte $02,$00,$00,$00,$0A,$28,$08,$19
            .byte $05,$FB,$F6,$7E,$6E,$00,$00,$00
            .byte $01,$00,$00,$00,$01,$04,$08,$04
            .byte $05,$FB,$9C,$64,$00,$00,$00,$00
            .byte $04,$0A,$14,$28,$01,$01,$09,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;------------------------------------------------
; Copy L4A00-L4AFF -> L0900-L09FF
;------------------------------------------------

L4A00:      .byte $02,$01,$01,$02,$02,$02,$02,$02
            .byte $02,$01,$02,$02,$02,$01,$02,$02
            .byte $02,$02,$01,$02,$02,$01,$01,$02
            .byte $01,$01,$03,$02,$02,$03,$02,$03
            .byte $02,$03,$03,$03,$03,$03,$01,$00
            .byte $03,$03,$03,$03,$02,$03,$03,$02
            .byte $02,$03,$02,$02,$02,$03,$02,$02
            .byte $02,$02,$03,$02,$02,$03,$03,$02
            .byte $03,$03,$01,$03,$03,$01,$02,$01
            .byte $02,$01,$02,$02,$02,$02,$03,$03
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A

L4A80:
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5A,$5A,$5A
            .byte $5A,$5A,$5A,$5A,$5A,$5D,$5F,$60
            .byte $62,$64,$66,$68,$6A,$6C,$6D,$6E
            .byte $70,$71,$72,$73,$74,$75,$76,$77
            .byte $78,$79,$7A,$7B,$7C,$7D,$7E,$7F
            .byte $80,$80,$80,$80,$00,$00,$00,$59
            .byte $57,$54,$52,$50,$4D,$4A,$48,$45
            .byte $42,$3F,$3C,$39,$36,$33,$30,$2D
            .byte $2A,$27,$24,$21,$1E,$1B,$18,$15
            .byte $12,$0F,$0C,$09,$06,$03,$00,$00
            .byte $00,$00,$02,$00,$04,$00,$06,$00
            .byte $08,$00,$0A,$00,$0C,$00,$0E,$00
            .byte $10,$00,$12,$00,$14,$00,$16,$00
            .byte $00,$02,$03,$02,$03,$02,$00,$38
            .byte $37,$1E,$DF,$DD,$0B,$00,$00,$00

;------------------------------------------------
; Copy L4B00-L4BFF -> L0A00-L0AFF
;------------------------------------------------

L4B00:      .byte $00,$06,$06,$0A,$0A,$1C,$0E,$00
            .byte $00,$C0,$12,$12,$1A,$1A,$31,$31
            .byte $30,$0D,$00,$FF,$FF,$FF,$FF,$00
            .byte $00,$00,$00,$9C,$70,$80,$A8,$C0
            .byte $2C,$94,$8A,$D8,$68,$1C,$1C,$28
            .byte $10,$48,$60,$AD,$40,$02,$FF,$FF
            .byte $02,$FE,$02,$FE,$2C,$CE,$86,$08
            .byte $08,$08,$08,$10,$00,$BD,$26,$0C
            .byte $68,$68,$30,$30,$38,$A8,$8D,$81
            .byte $0A,$02,$02,$01,$02,$01,$03,$20
            .byte $F1,$FF,$4E,$50,$95,$38,$05,$72
            .byte $C9,$25,$D0,$FF,$FF,$02,$FE,$02
            .byte $FE,$A5,$EC,$02,$FF,$FF,$FF,$FF
            .byte $FF,$FF,$7C,$0A,$C9,$00,$00,$01
            .byte $00,$00,$00,$7C,$0A,$68,$A8,$68
            .byte $AA,$68,$28,$60,$FF,$00,$40,$48
            .byte $01,$01,$01,$01,$01,$01,$01,$01
            .byte $01,$01,$01,$01,$D0,$C8,$40,$60
            .byte $70,$90,$B0,$C9,$A0,$D0,$06,$8D
            .byte $66,$66,$49,$49,$49,$49,$49,$68
            .byte $AA,$68,$85,$FC,$10,$13,$0F,$11
            .byte $FE,$FD,$94,$96,$97,$99,$9B,$68
            .byte $84,$08,$08,$08,$44,$44,$6F,$6F
            .byte $6F,$6F,$6F,$08,$08,$08,$08,$08
            .byte $05,$20,$06,$60,$07,$A0,$08,$E0
            .byte $0A,$20,$0B,$60,$0C,$A0,$0D,$E0
            .byte $0F,$20,$10,$60,$11,$A0,$12,$E0
            .byte $14,$20,$15,$60,$16,$A0,$17,$E0
            .byte $19,$20,$1A,$60,$1B,$A0,$1C,$E0
            .byte $1E,$20,$1F,$60,$20,$A0,$21,$E0
            .byte $23,$20,$24,$60,$25,$A0,$26,$E0
            .byte $28,$20,$29,$60,$2A,$A0,$2B,$00

;------------------------------------------------

L4C00:
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00

;--------------------------------------------
; Character definitions
;--------------------------------------------

L4E00:
            .byte $01,$02,$05,$0B,$17,$2F,$5F,$BF
            .byte $99,$CC,$66,$33,$99,$CC,$66,$33
            .byte $99,$33,$66,$CC,$99,$33,$66,$CC
            .byte $18,$2C,$2C,$5E,$5E,$BF,$87,$FF
            .byte $B5,$BB,$B5,$BB,$B5,$BB,$B5,$BB
            .byte $97,$AB,$97,$AB,$97,$AB,$97,$AB
            .byte $F3,$F3,$F3,$F3,$F3,$F3,$F3,$F3
            .byte $FF,$FF,$00,$CC,$99,$00,$FF,$FF
            .byte $FF,$FF,$00,$33,$99,$00,$FF,$FF
            .byte $3C,$42,$59,$55,$45,$39,$82,$7C
            .byte $80,$C0,$20,$30,$08,$0C,$02,$03
            .byte $3C,$5A,$B5,$BB,$B5,$BB,$56,$3C
            .byte $00,$7F,$83,$BC,$B8,$A0,$E0,$00
            .byte $A5,$42,$81,$18,$18,$81,$42,$A5
            .byte $92,$55,$28,$48,$BA,$1D,$FC,$18
            .byte $FF,$66,$24,$18,$18,$24,$5A,$A5
            .byte $04,$0B,$0B,$08,$08,$3E,$1C,$1C
            .byte $F0,$78,$3C,$1E,$3C,$78,$F0,$FF
            .byte $F0,$38,$1C,$0F,$0F,$C7,$E3,$F0
            .byte $3C,$7E,$5A,$FF,$BD,$99,$81,$66
            .byte $18,$BD,$FF,$5A,$7E,$FF,$BD,$A5
            .byte $7E,$AB,$D5,$7E,$66,$CC,$66,$CC
            .byte $00,$7E,$42,$5A,$5A,$42,$7E,$00
            .byte $00,$7E,$42,$42,$42,$42,$7E,$00
            .byte $3C,$42,$A5,$99,$66,$42,$24,$18
            .byte $FF,$FF,$FD,$BB,$D6,$72,$60,$40
            .byte $01,$03,$06,$0C,$19,$33,$66,$CC
            .byte $80,$C0,$60,$30,$98,$CC,$66,$33
            .byte $99,$CC,$E4,$76,$72,$66,$0C,$9F
            .byte $01,$02,$04,$08,$10,$20,$40,$80
            .byte $80,$40,$20,$10,$08,$04,$02,$01
            .byte $88,$AA,$AA,$22,$88,$AA,$AA,$22
            .byte $66,$BB,$57,$2E,$5E,$B5,$6B,$10
            .byte $18,$18,$10,$2C,$5E,$5E,$46,$3C
            .byte $10,$10,$10,$28,$38,$38,$5C,$AE
            .byte $7F,$7F,$7F,$00,$F7,$F7,$F7,$00
            .byte $7F,$7F,$7F,$00,$37,$17,$07,$00
            .byte $7F,$7F,$7F,$00,$F6,$F4,$F0,$00
            .byte $60,$40,$40,$00,$80,$80,$80,$00
            .byte $78,$60,$40,$00,$00,$00,$00,$00
            .byte $08,$34,$2E,$56,$5F,$BE,$8F,$7E
            .byte $03,$01,$01,$00,$00,$00,$00,$00
            .byte $1F,$07,$01,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$10,$10,$78,$EF,$83
            .byte $00,$40,$60,$00,$F0,$F4,$F6,$00
            .byte $11,$22,$44,$77,$77,$75,$55,$57
            .byte $57,$75,$57,$75,$57,$55,$77,$22
            .byte $4B,$5F,$3E,$9F,$3A,$79,$74,$D6
            .byte $EC,$F1,$FE,$78,$7D,$EE,$26,$4B
            .byte $BA,$B5,$BA,$BD,$BA,$B5,$BA,$BD
            .byte $AA,$55,$55,$AA,$AA,$55,$55,$AA
            .byte $07,$18,$27,$5F,$5F,$BF,$BE,$BD
            .byte $E0,$18,$E4,$FA,$FA,$FD,$7D,$BD
            .byte $BD,$BE,$BF,$5F,$5F,$27,$18,$07
            .byte $BD,$7D,$FD,$FA,$FA,$E4,$18,$E0
            .byte $BD,$BD,$BD,$BD,$BD,$BD,$BD,$BD
            .byte $FF,$00,$FF,$FF,$FF,$FF,$00,$FF
            .byte $01,$03,$07,$0F,$1F,$3F,$7F,$FF
            .byte $80,$C0,$E0,$F0,$F8,$FC,$FE,$FF
            .byte $FF,$00,$FF,$00,$FF,$00,$FF,$FF
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $AA,$55,$AA,$55,$AA,$55,$AA,$55
            .byte $DD,$EE,$77,$77,$EE,$DD,$00,$00
            .byte $18,$2C,$3C,$18,$08,$08,$FF,$FF
            .byte $10,$10,$10,$28,$28,$6C,$D6,$FF
            .byte $CC,$00,$33,$00,$99,$FF,$99,$00
            .byte $FE,$C6,$FE,$00,$7F,$63,$7F,$00
            .byte $C0,$C0,$30,$30,$0C,$0C,$03,$03
            .byte $03,$03,$0C,$0C,$30,$30,$C0,$C0
            .byte $60,$A0,$A0,$A0,$A0,$A0,$7F,$3C
            .byte $FF,$00,$7E,$42,$7E,$00,$00,$00
            .byte $99,$FF,$FF,$84,$A5,$A5,$A1,$07
            .byte $80,$40,$60,$50,$0A,$06,$02,$01
            .byte $FF,$00,$7F,$FF,$FF,$7F,$00,$FF
            .byte $00,$00,$F0,$EF,$EF,$F0,$00,$00
            .byte $DD,$1D,$EA,$77,$69,$9E,$B1,$DD
            .byte $3C,$2C,$2C,$5E,$B3,$BF,$46,$3C
            .byte $01,$02,$00,$08,$10,$00,$40,$80
            .byte $99,$00,$FF,$FF,$99,$99,$99,$FF
            .byte $E7,$24,$24,$E7,$18,$E7,$24,$E7
            .byte $50,$50,$50,$50,$59,$AF,$91,$6E
            .byte $7F,$7F,$5D,$55,$55,$14,$14,$10
            .byte $00,$C0,$E0,$30,$18,$0C,$07,$03
            .byte $FF,$FF,$55,$AA,$55,$AA,$FF,$FF
            .byte $CC,$00,$33,$00,$81,$FF,$81,$00
            .byte $18,$20,$40,$41,$41,$E2,$BC,$60
            .byte $3C,$E7,$3C,$00,$C3,$7E,$C3,$00
            .byte $FF,$81,$E7,$24,$24,$E7,$81,$FF
            .byte $FF,$00,$FF,$8E,$73,$BC,$4E,$04
            .byte $CC,$FF,$FF,$00,$99,$FF,$99,$00
            .byte $EF,$C5,$E7,$37,$9A,$FD,$EF,$CB
            .byte $F6,$BF,$FD,$FF,$EF,$DE,$7B,$F7
            .byte $C0,$C0,$00,$18,$18,$00,$03,$03
            .byte $22,$14,$D9,$3D,$3E,$7C,$52,$89
            .byte $F0,$17,$17,$F0,$0F,$E8,$E8,$0F
            .byte $B3,$B3,$B3,$B3,$B3,$B3,$B3,$B3
            .byte $7E,$56,$6E,$56,$6E,$56,$6E,$7E
            .byte $EE,$00,$77,$00,$EE,$00,$77,$00
            .byte $AA,$55,$AA,$00,$55,$AA,$55,$00
            .byte $99,$00,$99,$81,$7E,$81,$7E,$81
            .byte $3C,$7E,$EC,$F8,$F8,$FC,$7E,$3C
            .byte $3C,$42,$99,$C3,$BF,$BF,$7E,$3C
            .byte $9D,$DC,$B1,$BA,$A5,$F4,$35,$DF
            .byte $F0,$3C,$0F,$C3,$0F,$3C,$F0,$00
            .byte $F0,$C3,$0F,$3C,$0F,$C3,$F0,$FF
            .byte $AA,$BA,$A5,$25,$2B,$A8,$A9,$6D
            .byte $AA,$55,$AA,$54,$28,$50,$20,$00
            .byte $EE,$AA,$EE,$00,$00,$00,$00,$00
            .byte $EE,$AA,$EE,$00,$00,$00,$00,$00
            .byte $04,$4A,$A4,$40,$02,$25,$52,$20
            .byte $04,$02,$05,$48,$F0,$F0,$F8,$70
            .byte $FC,$FC,$FC,$00,$3F,$3F,$3F,$00
            .byte $10,$18,$2C,$2E,$5A,$5A,$5D,$BF
            .byte $FB,$B3,$5A,$DD,$C7,$E7,$5D,$0D
            .byte $7F,$77,$B7,$DB,$6D,$37,$3B,$0C
            .byte $7F,$B7,$F7,$5B,$AD,$F6,$B8,$40
            .byte $18,$3C,$66,$EB,$A7,$AB,$66,$3C
            .byte $A4,$4A,$A4,$4A,$A4,$4A,$A4,$4A
            .byte $00,$7E,$5D,$5D,$5E,$2C,$99,$7E
            .byte $FF,$BF,$BF,$46,$3C,$10,$60,$60
            .byte $FF,$BF,$BF,$46,$3C,$08,$06,$06
            .byte $99,$FF,$99,$99,$66,$00,$00,$00
            .byte $01,$02,$04,$08,$30,$F0,$E0,$E0
            .byte $FF,$81,$81,$81,$81,$81,$81,$FF
            .byte $FF,$99,$FF,$00,$00,$00,$00,$00
            .byte $01,$03,$06,$0D,$17,$3D,$6D,$BB
            .byte $80,$40,$E0,$B0,$D8,$74,$AE,$BB
            .byte $DE,$6B,$F7,$B7,$E0,$6A,$00,$00
            .byte $00,$00,$00,$00,$18,$34,$6E,$BB
            .byte $66,$FF,$66,$00,$00,$00,$00,$00
            .byte $CC,$33,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$24,$24,$7E,$FF
            .byte $02,$05,$0A,$05,$2A,$55,$2A,$55
            .byte $80,$40,$80,$40,$A8,$50,$AA,$55
            .byte $AA,$55,$AA,$55,$AA,$55,$AA,$55
            .byte $06,$1B,$34,$2C,$5C,$78,$A4,$8A
            .byte $F0,$20,$5C,$F4,$27,$3D,$09,$0F
            .byte $FF,$FF,$03,$0C,$30,$C0,$FF,$FF
            .byte $FF,$FF,$03,$0C,$30,$C0,$FF,$FF
            .byte $AA,$55,$AA,$00,$00,$00,$00,$00
            .byte $18,$18,$FF,$FF,$18,$18,$18,$18
            .byte $40,$E4,$4E,$44,$04,$00,$00,$00
            .byte $42,$24,$99,$99,$FF,$FF,$5A,$3C
            .byte $A0,$40,$28,$50,$0A,$14,$02,$05
            .byte $00,$18,$18,$7E,$7E,$18,$18,$00
            .byte $F8,$8F,$60,$FF,$00,$9F,$70,$8F
            .byte $AB,$AB,$AB,$AB,$AD,$B5,$B5,$AB
            .byte $C0,$C0,$E0,$F0,$FC,$FF,$FF,$FF
            .byte $03,$03,$07,$0F,$3F,$FF,$FF,$FF
            .byte $C0,$C0,$C0,$C0,$C0,$C0,$C0,$C0
            .byte $97,$97,$97,$97,$97,$97,$97,$97
            .byte $FF,$E7,$C3,$C3,$E7,$E7,$E7,$FF
            .byte $7E,$3C,$66,$CF,$87,$CF,$83,$7E
            .byte $E0,$B8,$BC,$BA,$BA,$A4,$98,$E0
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $03,$03,$0C,$0C,$30,$30,$C0,$C0
            .byte $FF,$FF,$00,$00,$00,$00,$00,$00
            .byte $03,$03,$03,$03,$03,$03,$03,$03
            .byte $99,$FF,$18,$FF,$81,$FF,$18,$FF
            .byte $0E,$03,$05,$09,$10,$20,$40,$80
            .byte $00,$70,$50,$70,$50,$BB,$FF,$EF
            .byte $00,$70,$78,$7C,$3E,$1E,$0E,$00
            .byte $FF,$40,$2F,$17,$0B,$05,$02,$01
            .byte $FF,$00,$FF,$FF,$FF,$FF,$00,$FF
            .byte $FF,$C0,$9F,$BF,$BF,$9F,$C0,$FF
            .byte $FB,$FB,$FB,$FB,$FB,$FB,$F8,$FB
            .byte $C0,$E0,$70,$59,$2F,$35,$19,$06
            .byte $FF,$40,$2F,$17,$0B,$05,$02,$01
            .byte $FF,$00,$FF,$FF,$FF,$FF,$FF,$7F
            .byte $DB,$6D,$B6,$DB,$6D,$B6,$DB,$6D
            .byte $FF,$00,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $F8,$04,$FA,$FC,$F1,$EF,$DF,$CF
            .byte $BF,$5F,$2F,$17,$17,$2F,$5F,$BF
            .byte $D3,$DC,$DF,$DF,$DF,$DF,$DF,$DF
            .byte $01,$02,$05,$0B,$17,$2F,$40,$FF
            .byte $7F,$FF,$FF,$FF,$FF,$FF,$00,$FF
            .byte $DF,$DF,$DF,$DF,$DF,$DF,$1F,$DF
            .byte $FF,$00,$FF,$FF,$FF,$FF,$FF,$FE
            .byte $FF,$02,$F4,$E8,$D0,$A0,$40,$80
            .byte $5F,$5F,$5F,$5F,$6F,$33,$1C,$07
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$00,$FF
            .byte $FD,$FA,$F4,$E8,$E8,$F4,$FA,$FD
            .byte $FE,$FF,$FF,$FF,$FF,$FF,$00,$FF
            .byte $80,$40,$A0,$D0,$E8,$F4,$02,$FF
            .byte $FF,$FF,$FF,$FF,$FF,$FF,$FF,$FF
            .byte $1F,$20,$5F,$3F,$8F,$F7,$FB,$F3
            .byte $CB,$3B,$FB,$FB,$FB,$FB,$FB,$FB
            .byte $FA,$FA,$FA,$FA,$F6,$CC,$38,$E0
            .byte $FB,$FB,$FB,$FB,$FB,$FB,$FB,$FB
            .byte $F0,$F0,$F0,$F0,$F0,$F0,$F0,$F0
            .byte $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
            .byte $18,$24,$DB,$DB,$24,$18,$18,$18

;--------------------------------------------
; Calculate screen address sprite
;
;   A = XPOS pixels
;   X = YPOS pixels
;--------------------------------------------

L5400:
;            and #$F8               ; 29 F8
;            sta L0090              ; 85 90
;            txa                    ; 8A
;            and #$07               ; 29 07
;            clc                    ; 18
;            adc L0090              ; 65 90
;            sta L0090              ; 85 90
;            txa                    ; 8A
;            lsr A                  ; 4A
;            lsr A                  ; 4A
;            and #$FE               ; 29 FE
;            tax                    ; AA
;            lda L0090              ; A5 90
;            clc                    ; 18
;            adc L0AC1,X            ; 7D C1 0A
;            sta L0090              ; 85 90
;            lda L0AC0,X            ; BD C0 0A
;            adc #$58               ; 69 58
;            sta L0091              ; 85 91
;            rts                    ; 60

	sty y_tmp
	stx x_tmp

	lsr a			; lb=X/8
	lsr a
	lsr a
	sta L0090

	txa
	and #7
	tay
	lda scrtab,y
	clc
	adc L0090
	sta L0090

	txa			; hb=Y/8+$80
	lsr a
	lsr a
	lsr a
	clc
	adc #>$8000
	sta L0091

	cpx #191
	bcc L5401
	lda L0091
	sec
	sbc #$20
	sta L0091
L5401:
	ldx x_tmp
	ldy y_tmp
	rts

x_tmp:	.byte 0
y_tmp:	.byte 0

scrtab:
	.byte $00,$20,$40,$60,$80,$a0,$c0,$e0

;--------------------------------------------
; Plot sprite
;--------------------------------------------

L5422:      jsr L5400              ; 20 00 54

            lda L0093              ; A5 93
            sta L5434+2              ; 8D 36 54
            sta L5461+2              ; 8D 36 54
            lda L0092              ; A5 92
            sta L5434+1              ; 8D 35 54
            sta L5461+1              ; 8D 36 54

            ldx L0094              ; A6 94
	bmi L545E

L5431:
            lda L0095              ; A4 95
            beq L5461

L5434:      lda L1111,X            ; BD 11 11
            and L0089              ; 25 89
	ldy spr_willy,x
            sta (L0090),Y          ; 91 90
            dex                    ; CA

;            tya                    ; 98
;            sbc #$08               ; E9 08
;            tay                    ; A8
;            bcs L5434              ; B0 F2
;            txa                    ; 8A
            bmi L545E              ; 30 19

	cpx #$0f
	bne L5434
	inc L0091
L5445:
	jmp L5434

;L5445:      inc L0090              ; E6 90
;            lda L0090              ; A5 90
;            bne L544D              ; D0 02
;            inc L0091              ; E6 91
;L544D:      bit L0098              ; 24 98
;            bne L5431              ; D0 E0
;            clc                    ; 18
;            adc #$38               ; 69 38
;            sta L0090              ; 85 90
;            lda L0091              ; A5 91
;            adc #$01               ; 69 01
;            sta L0091              ; 85 91
;            bpl L5431              ; 10 D3

L545E:      rts                    ; 60

; Small sprite 8x16

L5461:
	lda L1111,X		; Read sprite data
	and L0089		; Mask
	ldy spr_willy_s,x	; Get screenpointer
	sta (L0090),Y		; Plot byte on screen
	dex			; Next byte

	bmi L5460		; Check if 16 bytes plot

	cpx #$07		; Check if 8 bytes plot
	bne L5461

	inc L0091		; Jump 8 pixels down
	jmp L5461
L5460:
	jmp L545E

spr_willy:
	.byte $e0,$e1,$c0,$c1,$a0,$a1,$80,$81
	.byte $60,$61,$40,$41,$20,$21,$00,$01
	.byte $e0,$e1,$c0,$c1,$a0,$a1,$80,$81
	.byte $60,$61,$40,$41,$20,$21,$00,$01

spr_willy_s:
	.byte $e0,$c0,$a0,$80,$60,$40,$20,$00
	.byte $e0,$c0,$a0,$80,$60,$40,$20,$00

;--------------------------------------------
;
;     A    = XPOS
;     X    = YPOS
; Carry    = 0 - Copy backgroundmask to buffer
;            1 - Copy buffer to backgroundmask
; L0092/93 = Spritedata address
;--------------------------------------------

L545F:      ldy L0092              ; A4 92
            sty L5490+1              ; 8C 91 54
            sty L5481+1              ; 8C 82 54
            sty L5489+1              ; 8C 8A 54

            ldy L0093              ; A4 93
            sty L5490+2              ; 8C 92 54
            sty L5481+2              ; 8C 83 54
            sty L5489+2              ; 8C 8B 54

L5475:      jsr L5400              ; 20 00 54

;            ldx #$1F               ; A2 1F
;L547A:
;            ldy #$08               ; A0 08
;            sec                    ; 38
;L547D:      bcc L5490              ; 90 11
;            lda (L0090),Y          ; B1 90
;L5481:      and L1111,X            ; 3D 11 11
;            sta L4620,X            ; 9D 20 46
;            lda (L0090),Y          ; B1 90
;L5489:      ora L1111,X            ; 1D 11 11
;            sta (L0090),Y          ; 91 90
;            bcs L549C              ; B0 0C
;
;L5490:      lda L1111,X            ; BD 11 11
;            eor #$FF               ; 49 FF
;            and (L0090),Y          ; 31 90
;            ora L4620,X            ; 1D 20 46
;            sta (L0090),Y          ; 91 90
;
;L549C:      dex                    ; CA
;            tya                    ; 98
;            sbc #$08               ; E9 08
;            tay                    ; A8
;            bcs L547D              ; B0 DA
;            txa                    ; 8A
;            bmi L54BF              ; 30 19
;            inc L0090              ; E6 90
;            lda L0090              ; A5 90
;            bne L54AE              ; D0 02
;            inc L0091              ; E6 91
;L54AE:      bit L0098              ; 24 98
;            bne L547A              ; D0 C8
;            clc                    ; 18
;            adc #$38               ; 69 38
;            sta L0090              ; 85 90
;            lda L0091              ; A5 91
;            adc #$01               ; 69 01
;            sta L0091              ; 85 91
;            bpl L547A              ; 10 BB
;L54BF:      rts                    ; 60

	sec
L547D:
	bcc L547A

; Copy backgroundmask to buffer

	ldx #$1f		; Set bytecounter
L5477:
	ldy spr_willy,x		; Load screenpointer
	lda (L0090),y		; Get screendata
L5481:
	and L1111,x		; AND with spritedata
	sta L4620,x		; Save background in buffer

	lda (L0090),y		; Get screendata
L5489:
	ora L1111,x		; ORA with spritedata
	sta (L0090),y		; Put sprite on screen

	dex			; Next byte
	bmi L54BF		; If all bytes plotted, jump

	cpx #$0f		; If 16 bytes plotted
	bne L5477
	inc L0091		; Adjust screenaddress
	jmp L5477

; Copy buffer to backgroundmask

L547A:
	jsr $fe6b

	ldx #$1f
L547B:
	ldy spr_willy,x		; Load screenpointer
L5490:
	lda L1111,x		; Get spritedata
	eor #$FF		; Invert
	and (L0090),Y		; AND with screendata
	ora L4620,X		; ORA with buffer
	sta (L0090),Y		; Restore screen

	dex			; Next byte
	bmi L54BF		; If all bytes plotted, jump

	cpx #$0f		; If 16 bytes plotted
	bne L547B
	inc L0091		; Adjust screenaddress
	jmp L547B
L54BF:
	rts

;---------------------------------------------
; Read key in matrix
;
; Select row and read column:
;
; X = key to be checked
;
; columnbit = 0 - key pressed,
;             1 - key not pressed
;---------------------------------------------

L54C0:
	bit L0381		; Check controls
	bvs L54C2		; Control = Joykey
	bmi L54C3		; Control = JoyMMC

; Control = Keyboard

L54C1:
	lda key_row,x
	ora #$f0
	sta $b000		; Select row

	lda $b001		; Read column
	and key_column,x
	bne not_pressed
	lda key_return,x
	rts

not_pressed:
	lda #0
	rts
;                      L   R   U  ESC  W   E   JL  JR  JU
key_row:	.byte $01,$03,$06,$00,$04,$02,$00,$00,$00
key_column:	.byte $20,$20,$02,$20,$20,$08,$02,$08,$01
key_return:	.byte $fe,$02,$ff,$8f,$fe,$dd,$fe,$02,$ff

	ldx #0
            txa                    ; 8A
            rts                    ; 60

; Control = Joykey

L54C2:
	cpx #3			; ESC,W,E key
	bcs L54C1

	inx
	inx
	inx
	inx
	inx
	inx
	jmp L54C1

; Control = JoyMMC

L54C3:
	cpx #3			; ESC,W,E key
	bcs L54C1

	jsr joyget
	sta joy_scan

	cpx #0
	bne scan_r
scan_l:
	and #$02
	beq scan_no
	lda #$fe
	rts
scan_r:
	cpx #1
	bne scan_u
	lda joy_scan
	and #$01
	beq scan_no
	lda #$02
	rts
scan_u:
	cpx #2
	bne scan_no
	lda joy_scan
	and #$10
	beq scan_no
	lda #$ff
	rts
scan_no:
	lda #0
	rts

joy_scan:	.byte 0

;---------------------------------------------
; If cheat mode active (not in game):
;   W=next room,
;   E=previous room
;---------------------------------------------

L54C9:      lda L003E              ; A5 3E
            cmp #$2A               ; C9 2A
            bne L54EF              ; D0 20

            lda #$08               ; A9 08
            sta L009B              ; 85 9B

            ldx #$04               ; Scan-W
            jsr L54C0              ; 20 C0 54
            beq L54E1              ; F0 07

            ldx L0055              ; A6 55
            dex                    ; CA
            txa                    ; 8A

            jmp L1118              ; 4C 18 11

L54E1:      ldx #$05               ; Scan-E
            jsr L54C0              ; 20 C0 54
            beq L54EF              ; F0 07

            ldx L0055              ; A6 55
            inx                    ; E8
            txa                    ; 8A

            jmp L1118              ; 4C 18 11

L54EF:      rts                    ; 60

;---------------------------------------------

            bne L5509              ; D0 17
            lda L007B              ; A5 7B
            beq L556A              ; F0 74
            ldx #$00               ; A2 00
            stx L009A              ; 86 9A
            lda L0A24              ; AD 24 0A
L54FD:      inx                    ; E8
            cmp L09B6,X            ; DD B6 09
            bcc L54FD              ; 90 FA
            cpx #$02               ; E0 02
            bcc L555D              ; 90 56
            stx L009F              ; 86 9F
L5509:      cpx #$0F               ; E0 0F
            bcc L5511              ; 90 04
            lda #$00               ; A9 00
            sta L008B              ; 85 8B
L5511:      lda L0065              ; A5 65
            cmp #$0E               ; C9 0E
            bcs L555D              ; B0 46
            lda #$00               ; A9 00
            sta L0064              ; 85 64
            sta L0065              ; 85 65
            lda L0994,X            ; BD 94 09
            sec                    ; 38
            sbc #$04               ; E9 04
            and #$FE               ; 29 FE
            sta L0A1B              ; 8D 1B 0A
            lda L09B6,X            ; BD B6 09
            sec                    ; 38
            sbc #$06               ; E9 06
            bpl L5532              ; 10 02
            lda #$C0               ; A9 C0
L5532:      sta L0A24              ; 8D 24 0A
            lda L008E              ; A5 8E
            beq L556A              ; F0 31
            lda L005B              ; A5 5B
            eor L005C              ; 45 5C
            dex                    ; CA
            eor L008E              ; 45 8E
            bmi L554F              ; 30 0D
            inx                    ; E8
            lda L0AA6              ; AD A6 0A
            cmp L0055              ; C5 55
            bne L554E              ; D0 04
            cpx #$14               ; E0 14
            bcs L554F              ; B0 01
L554E:      inx                    ; E8
L554F:      stx L009F              ; 86 9F
            cpx #$03               ; E0 03
            bcs L556A              ; B0 15
            lda L0A24              ; AD 24 0A
            adc #$04               ; 69 04
            sta L0A24              ; 8D 24 0A
L555D:      lda L0A24              ; AD 24 0A
            and #$FC               ; 29 FC
            sta L0A24              ; 8D 24 0A
            lda #$00               ; A9 00
            sta L009F              ; 85 9F
            rts                    ; 60
L556A:      rts                    ; 60
            ldx #$FF               ; A2 FF
L556D:      inx                    ; E8
            lda L0C7E,X            ; BD 7E 0C
            jsr OSWRCH              ; 20 EE FF
            cmp #$04               ; C9 04
            bne L556D              ; D0 F5
            jsr L0CC4              ; 20 C4 0C
            jmp L0D2C              ; 4C 2C 0D
            .byte $00,$1F,$00,$14,$49,$74,$65,$6D
            .byte $73,$20,$63,$6F,$6C,$6C,$65,$63
            .byte $74,$65,$64,$20,$30,$30,$30,$20
            .byte $54,$69,$6D,$65,$20,$20,$37,$3A
            .byte $30,$30,$70,$6D,$04
            lda #$18               ; A9 18
            jsr L107B              ; 20 7B 10
            dec L0044              ; C6 44
            bne L55AE              ; D0 02
            inc L009E              ; E6 9E
L55AE:      inc L0041              ; E6 41
            lda L0041              ; A5 41
            cmp #$0A               ; C9 0A
            bcc L55C4              ; 90 0E
            inc L0042              ; E6 42
            ldx #$00               ; A2 00
            stx L0041              ; 86 41
            cmp L0042              ; C5 42
            bne L55C4              ; D0 04
            inc L0043              ; E6 43
            stx L0042              ; 86 42
L55C4:      ldx #$10               ; A2 10
            ldy L0043              ; A4 43
            jsr L0CD6              ; 20 D6 0C
            lda L0042              ; A5 42
            jsr L0CE5              ; 20 E5 0C
            lda L0041              ; A5 41
            jsr L0CE5              ; 20 E5 0C
            rts                    ; 60

;--------------------------------------------
; Print number Y at X,20
;--------------------------------------------

L55D6:
;            lda #$1F               ; A9 1F
;            jsr OSWRCH              ; 20 EE FF
;            txa                    ; 8A
;            jsr OSWRCH              ; 20 EE FF
;            lda #$14               ; A9 14
;            jsr OSWRCH              ; 20 EE FF
	stx XPOS
	lda #$14
	sta YPOS
            tya                    ; 98
            clc                    ; 18
            adc #$30               ; 69 30
            jsr OSWRCH              ; 20 EE FF
            rts                    ; 60

;--------------------------------------------

            .byte $C6,$57,$D0,$5B,$EE,$4C,$0D,$AD
            .byte $4C,$0D,$C9,$0A,$90,$32,$8C,$4C
            .byte $0D,$EE,$4D,$00,$33,$11,$00,$00
            .byte $00,$11,$33,$00,$00,$88,$CC,$66
            .byte $CC,$88,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$00,$00,$00

;------------------------------------------------

L5700:      jmp L57AF              ; 4C AF 57

;------------------------------------------------
; Sound
;------------------------------------------------

L5703:
	jsr sound
	rts
            lda L07E3,Y            ; B9 E3 07
            cmp L0016              ; C5 16
            bcc L572B              ; 90 21
            sta L0016              ; 85 16
            lda L07E0,Y            ; B9 E0 07
            sta L0010              ; 85 10
            lda L07E1,Y            ; B9 E1 07
            sta L0012              ; 85 12
            sta LFE06              ; 8D 06 FE
            lda L07E2,Y            ; B9 E2 07
            sta L0011              ; 85 11
            lda #$03               ; A9 03
            sta L0014              ; 85 14
            lda #$22               ; A9 22
            sta LFE07              ; 8D 07 FE
            lda #$20               ; A9 20
            sta L0015              ; 85 15
L572B:      rts                    ; 60

L572C:      ldy L0010              ; A4 10
            bne L5735              ; D0 05
            dec L0011              ; C6 11
            beq L5758              ; F0 24
            rts                    ; 60

L5735:      bpl L574E              ; 10 17
            lda L0015              ; A5 15
            eor #$02               ; 49 02
            sta L0015              ; 85 15
            sta LFE07              ; 8D 07 FE
            inc L0012              ; E6 12
            inc L0012              ; E6 12
            lda L0012              ; A5 12
            sta LFE06              ; 8D 06 FE
            dec L0011              ; C6 11
            beq L5758              ; F0 0B
            rts                    ; 60

L574E:      dec L0011              ; C6 11
            bne L5769              ; D0 17
            inc L0010              ; E6 10
            dec L0014              ; C6 14
            bne L5764              ; D0 0C
L5758:      lda #$20               ; A9 20
            sta LFE07              ; 8D 07 FE
            lda #$00               ; A9 00
            sta L0016              ; 85 16
            sta L0010              ; 85 10
            rts                    ; 60

L5764:      lda L0790,Y            ; B9 90 07
            sta L0011              ; 85 11
L5769:      lda L0013              ; A5 13
            clc                    ; 18
            adc L0793,Y            ; 79 93 07
            sta L0013              ; 85 13
            lda L0012              ; A5 12
            adc L0796,Y            ; 79 96 07
            sta L0012              ; 85 12
            sta LFE06              ; 8D 06 FE
            rts                    ; 60

;------------------------------------------------
; New IRQ vector
;------------------------------------------------

L577C:
            lda L00FC              ; A5 FC
            pha                    ; 48
            txa                    ; 8A
            pha                    ; 48
            tya                    ; 98
            pha                    ; 48
            ldx $00                ; A6 00
            lda LFE00              ; AD 00 FE
            and #$08               ; 29 08
            beq L579A              ; F0 0E
            inc L0004              ; E6 04

            ldx #$03               ; A2 03
            ldy #$F8               ; A0 F8
L5792:      dey                    ; 88
            bne L5792              ; D0 FD
            dex                    ; CA
            bne L5792              ; D0 FA

            ldx L0001              ; A6 01
L579A:      stx LFE09              ; 8E 09 FE
            txa                    ; 8A
            asl A                  ; 0A
            sta LFE08              ; 8D 08 FE

            jsr L572C              ; 20 2C 57

            pla                    ; 68
            tay                    ; A8
            pla                    ; 68
            tax                    ; AA
            pla                    ; 68
            sta L00FC              ; 85 FC
            jmp (L57C8)            ; 6C C8 57

;------------------------------------------------
; Set IRQ vec
;------------------------------------------------

L57AF:      sei                    ; 78
            lda L0204              ; AD 04 02
            sta L57C8              ; 8D C8 57
            lda L0205              ; AD 05 02
            sta L57C9              ; 8D C9 57
            lda #<L577C               ; A9 7C
            sta L0204              ; 8D 04 02
            lda #>L577C               ; A9 57
            sta L0205              ; 8D 05 02
            cli                    ; 58
            rts                    ; 60

L57C8:      .byte $00
L57C9:      .byte $00

;------------------------------------------------

L57CA:      .byte $F7,$40,$9A,$C0,$6F,$80,$5D
            .byte $80,$5F,$40,$A9,$00,$14,$80,$00
            .byte $00,$00,$00,$00,$00,$00,$00,$00
            .byte $00,$09,$40,$07,$90,$2E,$E0,$17
            .byte $68,$35,$70,$5D,$50,$37,$B8,$3F
            .byte $50,$5A,$20,$25,$F0,$0F,$80,$0A
            .byte $40,$01,$00,$00,$00,$00,$00
