<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:msxsl="urn:schemas-microsoft-com:xslt" exclude-result-prefixes="msxsl"
>
  <xsl:template match="projekt/sezon/rok">
    <xsl:for-each select="sezon">
      <xsl:sort data-type="number" case-order="lower-first"/>
      <xsl:value-of select="rok"/>
    </xsl:for-each>
    
  </xsl:template>
</xsl:stylesheet>
