<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <xsl:template match="author">
		Projekt "Moje Hobby" 
    <xsl:value-of select="name"/><xsl:text> </xsl:text>
    <xsl:value-of select="surname"/><xsl:text> </xsl:text>
    <xsl:value-of select="indeks"/><xsl:text> </xsl:text>
    <xsl:value-of select="kierunek"/><xsl:text> </xsl:text>
    <xsl:value-of select="group"/><xsl:text> </xsl:text>
	</xsl:template>
  

<xsl:template match="/swiat/ksiega/grupa/team">
    <html>
      <body>
        <table border="1">
          <tr>
            <th>Imie</th>
            <th>Magia</th>
            <th>Broń</th>
          </tr>
          <xsl:for-each select="postac">
            <tr>
              <td>
                <xsl:value-of select="imie"/>
              </td>
              <td>
                <xsl:value-of select="magia"/>
              </td>
              <td>
                <xsl:value-of select="bron"/>
              </td>
            </tr>
        </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
